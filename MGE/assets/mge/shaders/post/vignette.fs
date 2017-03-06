#version 430

uniform vec4 screenSize;

uniform sampler2D colorTexture;

in vec2 fragUV;

out vec4 fragColor;

void main(void)
{
	//Get the current fragment color
	fragColor = texture(colorTexture, fragUV);
	
	//Calculate relative position of fragment to the center
	const vec2 relativePosition = gl_FragCoord.xy / screenSize.xy - 0.5; //range -0.5...0.5
	
	//Get the distance of the fragment from the center
	const float distanceFromCenter = length(relativePosition);
	
	//Calculate vignette value
	const float vignette = smoothstep(0.7, 0.45, distanceFromCenter);
	
	//Mix the original color with the vignette color
	fragColor.rgb = mix(fragColor.rgb, fragColor.rgb * vignette, 0.7);
}