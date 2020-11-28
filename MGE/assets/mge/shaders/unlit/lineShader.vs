#version 430

uniform mat4 view;
uniform mat4 projection;

in vec3 vertex;
in vec3 color;

out vec3 fragColor;

void main (void)
{
	gl_Position = projection * view * vec4(vertex, 1.0f);
	fragColor = color;
}