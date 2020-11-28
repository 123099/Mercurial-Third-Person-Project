#version 330

uniform vec4 diffuseColor;

uniform sampler2D textureDiffuse;
uniform sampler2D texture2;

in vec2 texCoord;

out vec4 frag_color;

void main ( void )
{
	frag_color = diffuseColor * (texture(textureDiffuse, texCoord) + texture(texture2, texCoord)) ;
}