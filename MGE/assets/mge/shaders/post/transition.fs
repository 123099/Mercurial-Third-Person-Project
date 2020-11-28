#version 430

uniform float time;

uniform vec4 color;
uniform int direction;
uniform int isPlaying;

uniform sampler2D colorTexture;

in vec2 fragUV;

out vec4 fragColor;

void main(void)
{
	//Get the current fragment color
	fragColor = texture(colorTexture, fragUV);
	
	float mixValue = 0.0;
	if(isPlaying == 0)
		direction < 0 ? mixValue = 1.0 : 0.0;
	else
		mixValue = clamp(direction == 1 ? time * 0.5 : 1.0 - time*0.5, 0.0, 1.0);
	
	fragColor.rgb = mix(fragColor, color, mixValue).rgb;
}