#version 430

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

in vec3 vertex;
in vec3 normal;
in vec2 uv;
in vec4 tangent;

out vec4 vertex_cameraSpace;
out vec4 normal_cameraSpace;
out vec2 frag_uv;

out mat3 tbnMVMatrix;

void main ( void )
{	
	const mat4 mvMatrix = viewMatrix * modelMatrix;
	vertex_cameraSpace = mvMatrix * vec4(vertex, 1);
	normal_cameraSpace = mvMatrix * vec4(normal, 0);
	
	frag_uv = uv;
	
	//Calculate the tangent in camera space
	const vec4 tangent_cameraSpace = mvMatrix * tangent;
	
	//Calculate the column-major TBN matrix (from tangent to camera space)
	tbnMVMatrix[0] = normalize(tangent_cameraSpace.xyz);
	tbnMVMatrix[1] = normalize(cross(normal_cameraSpace.xyz, tangent_cameraSpace.xyz) * tangent.w);
	tbnMVMatrix[2] = normalize(normal_cameraSpace.xyz);
	
	//Transform the vertex to projection space
	gl_Position = projectionMatrix * vertex_cameraSpace;
}