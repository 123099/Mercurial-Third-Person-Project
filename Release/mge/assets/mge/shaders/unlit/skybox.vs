#version 430

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

in vec3 vertex;

out vec3 texCoord;

void main ( void )
{
	mat4 linearViewMatrix = mat4(mat3(viewMatrix));
	mat4 linearModelMatrix = mat4(mat3(modelMatrix));
	gl_Position = (projectionMatrix * linearViewMatrix * linearModelMatrix * vec4(vertex.xyz, 1));
	texCoord = vertex;
}