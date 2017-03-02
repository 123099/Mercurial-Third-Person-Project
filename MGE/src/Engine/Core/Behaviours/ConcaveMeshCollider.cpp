#include "ConcaveMeshCollider.hpp"
#include <Core\GameObject.hpp>
#include <Core\Mesh.hpp>

void ConcaveMeshCollider::SetupCollisionShape()
{
	//Get the mesh from the mesh renderer
	Mesh* mesh = m_gameObject->GetBehaviour<MeshRenderer>()->GetSharedMesh();

	//Create a bullet triangle mesh
	m_triangleMesh = std::make_unique<btTriangleMesh>(true, false);

	const std::vector<glm::vec3>& vertices = mesh->GetVertices();
	const glm::vec3 meshScale = m_gameObject->GetTransform()->GetLocalScale();

	//Add all the vertices in the mesh to the triangle mesh except the last one
	const int vertexCount = mesh->GetVertexCount();
	for (int i = 0; i < vertexCount - 3; i+=3)
	{
		const glm::vec3 v1 = vertices[i] * meshScale;
		const glm::vec3 v2 = vertices[i + 1] * meshScale;
		const glm::vec3 v3 = vertices[i + 2] * meshScale;
		m_triangleMesh->addTriangle(
			btVector3(v1.x, v1.y, v1.z),
			btVector3(v2.x, v2.y, v2.z),
			btVector3(v3.x, v3.y, v3.z)
		);
	}

	//Add the last 3 vertices to the triangle mesh, this time checking for duplicate vertices
	const glm::vec3 v1 = vertices[vertexCount - 3] * meshScale;
	const glm::vec3 v2 = vertices[vertexCount - 2] * meshScale;
	const glm::vec3 v3 = vertices[vertexCount - 1] * meshScale;
	m_triangleMesh->addTriangle(
		btVector3(v1.x, v1.y, v1.z),
		btVector3(v2.x, v2.y, v2.z),
		btVector3(v3.x, v3.y, v3.z),
		true
	);

	//Create the concave triangle mesh collider
	m_collisionShape = std::make_unique<btBvhTriangleMeshShape>(m_triangleMesh.get(), true, true);
}

