#version 430

uniform float contrast;

uniform sampler2D colorTexture;

in vec2 fragUV;

out vec4 fragColor;

void main(void)
{
	//Get the current fragment color
	fragColor = texture(colorTexture, fragUV);
	
	//Apply contrast
	fragColor.rgb = (fragColor.rgb - 0.5) * (1.0 + contrast) + 0.5;
}