#version 430

uniform vec4 fogColor;

uniform float fogDensity;
uniform float fogStartDistance;

uniform mat4 projectionMatrix;

uniform sampler2D colorTexture;
uniform sampler2D depthTexture;

in vec2 fragUV;

out vec4 fragColor;

//http://cs.gmu.edu/~jchen/cs662/fog.pdf
void main(void)
{
	//Get the current fragment colorTexture
	const vec4 currentColor = texture(colorTexture, fragUV);

	//Calculate the fog coord based on the z distance in cartesian plane of the fragment
	const float fragDepth = texture(depthTexture, fragUV).x;
	
	//Reconstruct the frag coordinate based on the depth value
	const float fogCoord = (-projectionMatrix[3][2]) / (fragDepth + projectionMatrix[2][2]);
	
	//Calculate the shift of the fogCoord from the origin
	const float fogCoordShifted = fogCoord - fogStartDistance;
	
	//If the shifted coordinate is whitin the starting distance, there should be no fog
	if(fogCoordShifted < -100)
	{
		fragColor = currentColor;
	}
	else
	{	
		//Calculate the fog factor using an exponential squared equation
		const float factor = clamp(1.0 - ( exp( -pow(( fogDensity * ( fogCoordShifted )), 2.0) ) ), 0.0, 1.0);
		
		fragColor = vec4(mix(currentColor, fogColor, factor).rgb, currentColor.a);
	}
}