#version 430

in vec3 vertex;
in vec2 uv;

out vec2 fragUV;

void main (void)
{
	gl_Position = vec4(vertex.xy, 0.0, 1.0);
	fragUV = uv;
}