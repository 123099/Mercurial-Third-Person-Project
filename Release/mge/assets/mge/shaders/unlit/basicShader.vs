#version 330

in vec3 vertex;
in vec2 uv;

uniform vec2 offset;

out vec2 fragmentUV;
//out vec2 fragmentOffset;

void main (void) {
    gl_Position = vec4(vertex,1) + vec4(offset,0,0);
    fragmentUV = uv;
	//fragmentOffset = offset;
}

