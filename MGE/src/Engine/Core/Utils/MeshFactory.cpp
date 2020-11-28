#include "MeshFactory.hpp"
#include <Core\Mesh.hpp>
#include <Utils\glm.hpp>
#include <vector>

Mesh * MeshFactory::CreateQuad()
{
	Mesh* mesh = new Mesh("Quad");

	std::vector<glm::vec3> vertices =
	{
		glm::vec3(-1.0f, -1.0f, 0.0f),
		glm::vec3(1.0f, -1.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 0.0f),
		glm::vec3(-1.0f, 1.0f, 0.0f)
	};

	std::vector<glm::vec2> uvs =
	{
		glm::vec2(0.0f, 0.0f),
		glm::vec2(1.0f, 0.0f),
		glm::vec2(1.0f, 1.0f),
		glm::vec2(0.0f, 1.0f)
	};

	std::vector<GLuint> triangles =
	{
		0, 1, 2,
		2, 3, 0
	};

	mesh->SetVertices(vertices);
	mesh->SetUVs(uvs);
	mesh->SetTriangles(triangles);

	mesh->UploadMeshData();

	return mesh;
}
