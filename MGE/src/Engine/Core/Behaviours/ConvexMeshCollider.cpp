#include <Behaviours\ConvexMeshCollider.hpp>
#include <Core\Mesh.hpp>
#include <Core\GameObject.hpp>

void ConvexMeshCollider::Start()
{
	//Retrieve the mesh from the mesh renderer
	Mesh* mesh = m_gameObject->GetBehaviour<MeshRenderer>()->GetSharedMesh();

	if (mesh == nullptr)
	{
		std::cerr << "[Warning - GameObject: " << m_gameObject->GetName() << "] Cannot initialize mesh collider without a mesh set in a mesh renderer!" << '\n';
	}
	else
	{
		//Go through all the points of the mesh, and add them to the collision shape
		const std::vector<glm::vec3> vertices = mesh->GetVertices();
		btConvexHullShape* convexMeshShape = dynamic_cast<btConvexHullShape*>(m_collisionShape.get());

		for (const auto& vertex : vertices)
		{
			convexMeshShape->addPoint(btVector3(vertex.x, vertex.y, vertex.z), false);
		}

		//Recalculate shape AABB
		convexMeshShape->recalcLocalAabb();
	}
}

void ConvexMeshCollider::SetupCollisionShape()
{
	m_collisionShape = std::make_unique<btConvexHullShape>();
}
