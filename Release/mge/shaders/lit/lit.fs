#version 430
const vec4 gamma = vec4(1.0 / 2.2);

uniform vec4 globalAmbient;
uniform vec4 fogColor;
uniform float fogStartDistance;
uniform float fogDensity;

uniform vec4 materialAmbient;
uniform vec4 materialDiffuse;
uniform vec4 materialSpecular;
uniform vec4 materialEmission;
uniform float materialShininess;
uniform float materialReflectivity;

uniform sampler2D diffuseTexture;
uniform sampler2D normalMap;
uniform sampler2D specularMap;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform samplerCube environmentMap;

//GLSL structure definition rules:
//1. DO NOT USE VEC3. GLSL really dislikes 3 component data values and doesn't handle them well. Stick to 1, 2, or 4 sized values
//2. Every vec4 has to end on a 4N padding. Therefore, declare all the vec4s first, and then any following values in decreasing byte size requirements
struct Light
{
	vec4 position_cameraSpace;
	vec4 direction_cameraSpace;
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 attenuation;
	float type;
	float intensity;
	float spotInnerAngleCos;
	float spotOuterAngleCos;
	mat4 vpMatrix;
};

layout (std430) buffer lightData
{
	Light lights[];
};

struct ShadowMapFix
{
	sampler2D shadowMap;
};
uniform ShadowMapFix shadowMaps[10];

in vec4 vertex_worldSpace;
in vec4 vertex_cameraSpace;
in vec4 normal_cameraSpace;
in vec2 frag_uv;
in mat3 tbnMVMatrix;

out vec4 fragColor;

vec4 calculateNormalizedLightVector(int lightIndex)
{
	//Calculate light vector based on light type
	const vec4 L = 
		lights[lightIndex].type == 0.0 ?
			lights[lightIndex].direction_cameraSpace : //Directional
			vertex_cameraSpace - lights[lightIndex].position_cameraSpace; //Point or Spot
	
	//Normalize and invert the light vector to point towards the light source
	return -normalize(L);
}

vec4 calculateAmbient(int lightIndex)
{
	return materialAmbient * lights[lightIndex].ambient;
}

vec4 calculateDiffuse(int lightIndex, vec4 normalizedLightVector, vec4 normal)
{	
	//Calculate the diffuse component based on the angle between the light vector and the normal vector
	return max(dot(normalizedLightVector, normal), 0.0) * lights[lightIndex].diffuse * materialDiffuse;
}

vec4 calculateSpecular(int lightIndex, vec4 normalizedLightVector, vec4 normal)
{
	//Reflect the light vector along the fragment normal
	const vec4 reflectedLightDir = reflect(normalizedLightVector, normal);
	
	//Get the angle between the reflected light vector and the fragment vector towards the camera
	const float cosAngleReflectedView = max(dot(normalize(reflectedLightDir), normalize(vertex_cameraSpace)), 0.0);
	
	//Make sure shininess is positive, otherwise the pow behaviour is undefined.
	const float shininess = materialShininess <= 0 ? 1.0 : materialShininess;
	
	return pow(cosAngleReflectedView, shininess) * lights[lightIndex].specular * materialSpecular * texture(specularMap, frag_uv).a;
}

float calculateAttenuation(int lightIndex)
{
	float attenuation = 1.0;
	
	if(lights[lightIndex].type != 0.0) //Anything but directional light
	{
		//Get the distance squared to the light source
		vec4 lv = vertex_cameraSpace - lights[lightIndex].position_cameraSpace;
		float distSquared = dot(lv, lv); //DRIVER BUG!!!! dot(lv, lv) doesn't equal lv.x * lv.x + lv.y * lv.y
		
		//Get the attenuation factors of the light
		vec4 lightAttenuation = lights[lightIndex].attenuation;
		
		//Calculate attenuation based on the formula (1 / c1 + c2*dist + c3 * dist * dist)
		attenuation = 1.0 / (lightAttenuation.x + lightAttenuation.y * sqrt(distSquared) + lightAttenuation.z * distSquared);
	}
	
	return attenuation;
}

vec4 calculateFragmentNormal()
{
	//Retrieve the color of the normal from the normal map
	vec4 normalColor = texture(normalMap, frag_uv);
	
	//If the color is black, the most probable cause is that the normal map wasn't set. In that case, use the normal of the mesh, otherwise, calculate the normal from the map
	if(normalColor != vec4(0.0))
	{
		return normalize(vec4(tbnMVMatrix * (255.0/128.0 * normalColor.xyz - 1.0), 0.0));
	}
	else
	{
		return normalize(normal_cameraSpace);
	}
}

float calculateShadowAttenuation(int index)
{
	vec4 vertexLightSpace = lights[index].vpMatrix * vec4(vertex_worldSpace.xyz, 1.0);
	vec3 projectedCoords = 0.5 * (vertexLightSpace.xyz / vertexLightSpace.w) + vec3(0.5);
	
	if(projectedCoords.z > 1.0)
	{
		return 1.0;
	}
	
	float closestDepth = texture(shadowMaps[index].shadowMap, projectedCoords.xy).x;
	
	if(closestDepth < projectedCoords.z + 0.05)
	{
		return 0.1;
	}
	
	return 1.0;
}

vec4 calculateLight(int index, vec4 normal)
{
	if(lights[index].intensity == 0.0)
	{
		return vec4(0.0);
	}
	
	const vec4 L = calculateNormalizedLightVector(index);
	
	//Calculate the cos of the angle of the fragment from the light's direction
	const float currentAngleCos = dot(L, -normalize(lights[index].direction_cameraSpace));
	
	//Calculate the spotlight falloff intensity variable
	//When inside the inner cone, the falloff is 1
	//When outside the inner cone, but inside the outer cone, the falloff is between 0 and 1
	//When outside the outer cone, then falloff is 0
	float spotFalloff = 1.0;
	
	//If the fragment is inside the inner cone, the falloff is 1, otherwise, it decreases according to (angleCos - outerConeCos) / (innerConeCos - outerConeCos)
	if(currentAngleCos <= lights[index].spotInnerAngleCos) //As cos increases, angle decreases
	{
		//Calculate the difference in cosine between both cones
		const float innerMinusOuterAngleCos = lights[index].spotInnerAngleCos - lights[index].spotOuterAngleCos;
		
		//The falloff is the ratio between the current angle between both cones and the difference between both cones
		spotFalloff = clamp((currentAngleCos - lights[index].spotOuterAngleCos) / innerMinusOuterAngleCos, 0.0, 1.0);
	}

	const float shadowAttenuation = calculateShadowAttenuation(index);
	
	const vec4 ambient = calculateAmbient(index);
	const vec4 diffuse = calculateDiffuse(index, L, normal);
	const vec4 specular = calculateSpecular(index, L, normal);
	
	vec3 ambientAndDiffuse = ambient.xyz + diffuse.xyz * shadowAttenuation;
	
	//Decide whether to apply a diffuse texture or not
	const vec4 diffuseTextureColor = pow(texture(diffuseTexture, frag_uv), gamma);
	if(diffuseTextureColor != vec4(0.0))
	{
		ambientAndDiffuse *= diffuseTextureColor.xyz;
	}
	
	return vec4((ambientAndDiffuse.xyz + specular.xyz * shadowAttenuation) * vec3(lights[index].intensity * calculateAttenuation(index) * spotFalloff), (ambient.a + diffuse.a + specular.a) * 0.34);
}

vec4 calculateReflection(vec4 currentColor)
{
	if(materialReflectivity == 0.0)
	{
		return currentColor;
	}
	
	//Calculate vector to skybox in world space since the environment map pixels are in world space and camera translation should be ignored
	const vec3 direction = vec3(transpose(viewMatrix) * vec4(reflect(vertex_cameraSpace, normal_cameraSpace).xyz, 0));
	
	//Calculate reflection of the environment map
	return vec4(mix(currentColor, pow(texture(environmentMap, direction), gamma), materialReflectivity).xyz, currentColor.a);
}

vec4 calculateFog(vec4 currentColor)
{
	//Calculate the fog coord based on the z distance in cartesian plane of the fragment
	const float fogCoord = abs(vertex_cameraSpace.z / vertex_cameraSpace.w);
	
	//Calculate the shift of the fogCoord from the origin
	const float fogCoordShifted = fogCoord - fogStartDistance;
	
	//If the shifted coordinate is whitin the starting distance, there should be no fog
	if(fogCoordShifted < 0)
	{
		return currentColor;
	}
	
	//Calculate the fog factor using an exponential squared equation
	const float factor = clamp(1.0 - ( exp( -pow(( fogDensity * ( fogCoordShifted )), 2.0) ) ), 0.0, 1.0);
	
	return vec4(mix(currentColor, fogColor, factor).xyz, currentColor.a);
}

void main ( void )
{
	const vec4 normal = calculateFragmentNormal();
	
	//Retrieve the light count
	const int lightCount = lights.length();
	
	//Go through all the lights this shader supports, calculate its color contribution and add it to the final color
	for(int i = 0; i < lightCount; ++i)
	{	
		fragColor += calculateLight(i, normal);
	}
	
	//Add the global ambient and emission color of the material
	fragColor += vec4(globalAmbient.xyz + materialEmission.xyz, (globalAmbient.a + materialEmission.a + fragColor.a) * 0.34);
	
	//Apply reflection
	fragColor = calculateReflection(fragColor);
	
	//Apply fog
	fragColor = calculateFog(fragColor);

	/*vec4 vertexLightSpace = lights[1].vpMatrix * vec4(vertex_worldSpace.xyz, 1.0);
	vec3 projectedCoords = 0.5 * (vertexLightSpace.xyz / vertexLightSpace.w) + vec3(0.5);
	float closestDepth = texture(shadowMaps[1], projectedCoords.xy).x;
	fragColor = vec4(closestDepth);*/
	
	//fragColor = texture(shadowMaps1, frag_uv);
}











