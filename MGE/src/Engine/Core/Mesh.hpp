#ifndef MESH_H
#define MESH_H

#include <Utils\glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <string>
#include <Utils\InstanceCache.hpp>

/**
 * A mesh represents vertices, normals, UVs and tangents. It knows how data should be buffered to OpenGL
 * and how it should be streamed to OpenGL
 */
class Mesh : public ICacheable
{
public:
	static InstanceCache<Mesh>& GetCache();

	Mesh(std::string name);
	virtual ~Mesh();

	std::vector<glm::vec3> GetVertices();
	std::vector<glm::vec3> GetNormals();
	std::vector<glm::vec2> GetUVs();
	std::vector<uint32_t> GetTriangles();

	void SetVertices(std::vector<glm::vec3> vertices);
	void SetNormals(std::vector<glm::vec3> normals);
	void SetUVs(std::vector<glm::vec2> uvs);
	void SetTriangles(std::vector<GLuint> triangles);

	const std::vector<glm::vec3>& GetVertices() const;

	size_t GetVertexCount();
	size_t GetTriangleCount();

	void CalculateTangents(bool flipBinormals = false);
        
	void UploadMeshData();

    // Streams the mesh to OpenGL using the given indices for the different attributes
    void StreamToOpenGL(GLint verticesAttrib, GLint normalsAttrib, GLint UVsAttrib, GLint tangentsAttrib);

    // Draws debug info (normals) for the mesh using the given matrices)
    void drawDebugInfo(const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix);
protected:
	static InstanceCache<Mesh> s_meshCache;

    //OpenGL ID's for the different buffers created for this mesh
	GLuint m_indexBufferID;
	GLuint m_vertexBufferID;
	GLuint m_normalBufferID;
	GLuint m_uvBufferID;
	GLuint m_tangentBufferID;

	//the actual data
	std::vector<glm::vec3> m_vertices;       //vec3 with 3D coords for all vertices
	std::vector<glm::vec3> m_normals;        //vec3 with 3D normal data
	std::vector<glm::vec2> m_uvs;            //vec2 for UVs
	std::vector<glm::vec4> m_tangents;		 //vec4 for tangents to every vertex. The w component indicates whether the binormal should be flipped or not

	//List of triangles that contains indices into the vertex, normals, uvs and tangents vectors
	std::vector<uint32_t> m_triangles;

    //Buffer vertices, normals, tangents and UV's
	void Buffer();
};

#endif // MESH_H
