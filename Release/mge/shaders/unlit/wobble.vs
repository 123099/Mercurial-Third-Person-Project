#version 330

uniform mat4 mvpMatrix;

uniform float time;

in vec3 vertex;
in vec2 uv;

out vec2 texCoord;

void main( void )
{
	float sinEq = sin(vertex.x * 2 + time);
	float cosEq = cos(vertex.y * 2 + time);
	float dotResult = dot(normalize(vertex), vec3(0,0,1));
	float a = dotResult * sin(time);
	gl_Position = mvpMatrix * vec4(vertex + vec3(cosEq, sinEq, a * vertex.z), 1);
	
	texCoord = uv;
}