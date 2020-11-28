#version 430

uniform mat4 mvpMatrix;

in vec3 vertex;
in vec2 uv;

out vec2 fragUV;

void main( void )
{
	gl_Position = mvpMatrix * vec4(vertex, 1);
	
	fragUV = uv;
}