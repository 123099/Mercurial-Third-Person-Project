#version 430

uniform float time;
uniform sampler2D diffuseTexture;

in vec2 fragUV;

out vec4 fragColor;

void main(void)
{
	fragColor = texture(diffuseTexture, fragUV + vec2(time) * 0.01);
}