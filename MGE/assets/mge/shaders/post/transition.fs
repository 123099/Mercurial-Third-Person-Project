#version 430

uniform float time;

uniform sampler2D colorTexture;

in vec2 fragUV;

out vec4 fragColor;

void main(void)
{
	//Get the current fragment color
	fragColor = texture(colorTexture, fragUV);
	
	//whiten something
	fragColor.rgb += vec3(0.6)*time;
}