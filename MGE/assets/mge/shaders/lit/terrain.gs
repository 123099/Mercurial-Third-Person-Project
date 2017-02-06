#version 430

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform mat4 projectionMatrix;

in vec2 geometry_uv[3];
in float animateUV[3];

out float frag_animateUV;
out vec2 frag_uv;
out vec4 vertex_cameraSpace;
out vec4 normal_cameraSpace;

void main ( void )
{
	//Get 2 edges of the triangle
	vec4 edge1_cameraSpace = gl_in[1].gl_Position - gl_in[0].gl_Position;
	vec4 edge2_cameraSpace = gl_in[2].gl_Position - gl_in[0].gl_Position;
	
	//Calculate the normal for the triangle
	vec4 normal = vec4(normalize(cross(edge1_cameraSpace.xyz, edge2_cameraSpace.xyz)), 0);
	
	for(int i = 0; i < 3; ++i)
	{
		gl_Position = projectionMatrix * gl_in[i].gl_Position;
		frag_animateUV = animateUV[i];
		frag_uv = geometry_uv[i];
		vertex_cameraSpace = gl_in[i].gl_Position;
		normal_cameraSpace = normal;
		EmitVertex();
	}
}