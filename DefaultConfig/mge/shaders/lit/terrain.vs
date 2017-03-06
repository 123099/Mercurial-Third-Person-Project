#version 430

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

uniform int maxHeight;
uniform sampler2D heightMap;

uniform float waveFrequency;
uniform float waveSpeed;
uniform float waveHeight;
uniform float time;

in vec3 vertex;
in vec2 uv;

out vec2 geometry_uv;
out float animateUV;

void main ( void )
{
	animateUV = 0;
	geometry_uv = uv;
	
	//Get the height of the vertex from the height map
	float height = texture(heightMap, uv).r * maxHeight;
	
	//Apply height to vertex
	vec4 newVertex = vec4(vertex.x, vertex.y + height, vertex.z, 1);
	
	//Translate the vertex, moving it to world space
	newVertex += vec4(modelMatrix[3].xyz, 0);
	
	//Apply wave effect to vertices on the water level
	if(height < 2.0f)
	{
		float offset = dot(newVertex.xz, newVertex.xz);
		
		//Translate the vertex towards the origin of the terrain with respect to time in a sin function
		newVertex.y += waveHeight * sin(time * waveSpeed + waveFrequency * offset);
		
		animateUV = 1.0;
	}
	
	//Set the vertex position in camera space. This is for the geometry shader to pass on to the fragment shader
	//The geometry shader will then transform the position from camera space to projection space for OpenGL
	gl_Position = viewMatrix * newVertex;
}