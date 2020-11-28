#version 430
const vec4 gamma = vec4(1.0 / 2.2);

uniform sampler2D splatMap;
uniform sampler2D diffuseTexture0;
uniform sampler2D diffuseTexture1;
uniform sampler2D diffuseTexture2;
uniform sampler2D diffuseTexture3;

uniform float time;
uniform float waveSpeed;

uniform vec4 globalAmbient;

uniform vec4 materialAmbient;
uniform vec4 materialDiffuse;
uniform vec4 materialSpecular;
uniform vec4 materialEmission;
uniform float materialShininess;

uniform mat4 viewMatrix;
uniform samplerCube environmentMap;

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
};

layout (std430) buffer lightData
{
	Light lights[];
};

in vec4 vertex_cameraSpace;
in vec4 normal_cameraSpace;
in vec2 frag_uv;
in float frag_animateUV;

out vec4 fragColor;

vec4 calculateNormalizedLightVector(int lightIndex)
{
	//Calculate light vector based on light type
	vec4 L = vec4(0.0);
	
	if(lights[lightIndex].type == 0.0) //Directional
	{
		L = lights[lightIndex].direction_cameraSpace;
	}
	else //Point or Spot
	{
		L = vertex_cameraSpace - lights[lightIndex].position_cameraSpace;
	}
	
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
	vec4 reflectedLightDir = reflect(normalizedLightVector, normal);
	
	//Get the angle between the reflected light vector and the fragment vector towards the camera
	float cosAngleReflectedView = max(dot(normalize(reflectedLightDir), normalize(vertex_cameraSpace)), 0.0);
	
	//Make sure shininess is positive, otherwise the pow behaviour is undefined.
	float shininess = materialShininess;
	if(shininess <= 0.0) shininess = 1.0;
	
	return pow(cosAngleReflectedView, shininess) * lights[lightIndex].specular * materialSpecular;
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

vec4 calculateLight(int index, vec4 normal)
{
	if(lights[index].intensity == 0.0)
	{
		return vec4(0.0);
	}
	
	vec4 L = calculateNormalizedLightVector(index);
	
	//Calculate the cos of the angle of the fragment from the light's direction
	float currentAngleCos = dot(L, -normalize(lights[index].direction_cameraSpace));
	
	//Calculate the spotlight falloff intensity variable
	//When inside the inner cone, the falloff is 1
	//When outside the inner cone, but inside the outer cone, the falloff is between 0 and 1
	//When outside the outer cone, then falloff is 0
	float spotFalloff = 1.0;
	
	//If the fragment is inside the inner cone, the falloff is 1, otherwise, it decreases according to (angleCos - outerConeCos) / (innerConeCos - outerConeCos)
	if(currentAngleCos <= lights[index].spotInnerAngleCos) //As cos increases, angle decreases
	{
		//Calculate the difference in cosine between both cones
		float innerMinusOuterAngleCos = lights[index].spotInnerAngleCos - lights[index].spotOuterAngleCos;
		
		//The falloff is the ratio between the current angle between both cones and the difference between both cones
		spotFalloff = clamp((currentAngleCos - lights[index].spotOuterAngleCos) / innerMinusOuterAngleCos, 0.0, 1.0);
	}

	vec4 ambient = calculateAmbient(index);
	vec4 diffuse = calculateDiffuse(index, L, normal);
	vec4 specular = calculateSpecular(index, L, normal);
	
	return (ambient + diffuse + specular) * vec4(vec3(lights[index].intensity * calculateAttenuation(index) * spotFalloff), 1.0);
}

vec4 calculateTerrainTexture()
{
	//Same story as with the height map in the vertex shader about gamma
	vec4 splatColor = texture(splatMap, frag_uv);
	
	//Sample each of the diffuse textures and mix a color based on the splat map
	/*for(int i = 0; i < 4; ++i)
	{
		fragColor += vec4(splatColor[i] * vec3(texture(ss[i].t, frag_uv)), 1);
	}*/
	
	//Tile the UV coordinate for increased detail
	vec2 tiledUV = mod(frag_uv * 10.0, 1.0);
	vec2 animatedUV = tiledUV;
	if(frag_animateUV > 0)
		//animatedUV += vec2(-0.01f * sin(waveSpeed * time * 0.2f + 0.01f * dot(tiledUV, tiledUV)), 0.01f * sin(waveSpeed * time * 0.2f + 0.002f * dot(tiledUV, tiledUV)));
		animatedUV += vec2(mod(tiledUV.x + 0.05 * time, 1.0), mod(tiledUV.y + 0.05 * time, 1.0));
	
	return vec4(
		vec3(
			splatColor.r * texture(diffuseTexture0, tiledUV) +
			splatColor.g * texture(diffuseTexture1, animatedUV) +
			splatColor.b * texture(diffuseTexture2, tiledUV) +
			splatColor.a * texture(diffuseTexture3, tiledUV)
		), 1);
}

void main ( void )
{	
	//Initialize the color
	fragColor = vec4(0);
	
	//Retrieve the light count
	const int lightCount = lights.length();

	//Go through all the lights this shader supports, calculate its color contribution and add it to the final color
	for(int i = 0; i < lightCount; ++i)
	{	
		fragColor += calculateLight(i, normal_cameraSpace);
	}
	
	//Add the global ambient and emission color of the material
	fragColor += globalAmbient + materialEmission;
	
	//Apply the light color to the terrain texture
	fragColor *= calculateTerrainTexture();
	
	//Calculate vector to skybox in world space since the environment map pixels are in world space
	vec3 direction = transpose(mat3(viewMatrix)) * reflect(vertex_cameraSpace, normal_cameraSpace).xyz;
	
	//Apply reflection
	fragColor = mix(fragColor, texture(environmentMap, direction), 0.1);
	
	//Apply gamma adjustments to coincide with the monitor being darker than it actually is
	fragColor = pow(fragColor, gamma);
}
