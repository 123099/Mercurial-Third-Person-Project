#version 430
const vec4 gamma = vec4(1.0/2.2);

uniform samplerCube skybox;

uniform vec4 tintColor;
uniform float exposure;

in vec3 texCoord;
out vec4 fragColor;

void main ( void )
{
	fragColor = texture(skybox, texCoord) * tintColor;
	fragColor = pow(vec4(vec3(fragColor) * exposure, fragColor.a), gamma);
}