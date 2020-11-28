#version 330

in vec2 fragmentUV;
//in vec2 fragmentOffset;
out vec4 sColor;

uniform vec2 offset;
uniform vec2 mousePosition;
uniform float radius;

void main (void) 
{
// Calculate whether the uv coordinate is in the 1st or 2nd part of its division in its axis
// Only if the u and the v are in different halves, return the red color. Otherwise, return green.
//	  T   F
//	|---|---|
//	| R | G | F
//	|---|---|
//	| G | R | T
//	|---|---|

	if(mod(fragmentUV.x, 0.2f) < 0.1f ^^ mod(fragmentUV.y, 0.2f) < 0.1f)
	{
		sColor = vec4(1,0,0,1);
	}
	else
	{
		sColor = vec4(0,1,0,1);
	}
	
	//Light Shader
	//As the distance of the fragment increases from the center, decrease the color of the fragment with respect to its distance squared
	
	//Translate the coordinate of the fragment to be relative to the mouse position
	vec2 localPos = gl_FragCoord.xy - mousePosition + offset;
	
	//Get the distance of the local UV coordinate from the center of the circle
	float distanceSquared = localPos.x * localPos.x + localPos.y * localPos.y; //dot(localPos, localPos);
	
	//Get the radius squared for more optimized comparisons
	float radiusSquared = radius * radius;
	
	//Calculate a difference between the current distance squared and the threshold distance squared of the color swap (increase the color to make it brighter or decrease for darker)
	float delta = distanceSquared - 0.25f * radiusSquared;
	
	//If the delta is negative, we are inside the inner circle, add the color at a much larger rate
	if(delta < 0 )
	{
		sColor += vec4(-delta * 0.001f);
	}
	else
	{
		//Update the color to reflect the distance away from the inner circle
		sColor -= vec4(delta * 0.000005f);
	}
}

