//DIFFUSE COLOR VERTEX SHADER

#version 330 // for glsl version (12 is for older versions , say opengl 2.1

in vec3 vertex;

uniform	mat4 mvpMatrix;

void main( void )
{
	gl_Position = mvpMatrix * vec4(vertex, 1.f);
}
