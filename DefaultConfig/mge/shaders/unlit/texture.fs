//DIFFUSE TEXTURE FRAGMENT SHADER
#version 330 // for glsl version (12 is for older versions , say opengl 2.1

uniform sampler2D textureDiffuse;
in vec2 texCoord;
out vec4 fragment_color;

void main( void ) {
	fragment_color = pow(texture(textureDiffuse,texCoord), vec4(1.0/2.2));
}
