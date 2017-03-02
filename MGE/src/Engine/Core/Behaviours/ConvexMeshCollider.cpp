#include <Behaviours\ConvexMeshCollider.hpp>
#include <Core\Mesh.hpp>
#include <Core\GameObject.hpp>
#include <bullet\BulletCollision\CollisionShapes\btShapeHull.h>

void ConvexMeshCollider::SetupCollisionShape()
{
	btConvexHullShape convexHullShape;						  //Complex shape
	m_collisionShape = std::make_unique<btConvexHullShape>(); //Simplified shape

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
		const glm::vec3 meshScale = m_gameObject->GetTransform()->GetLocalScale();

		for (const auto& vertex : vertices)
		{
			convexHullShape.addPoint(btVector3(vertex.x * meshScale.x, vertex.y * meshScale.y, vertex.z * meshScale.z), false);
		}

		//Recalculate shape AABB
		convexHullShape.recalcLocalAabb();

		//Create a Hull approximation to reduce vertex count
		btShapeHull shapeHull(&convexHullShape);
		shapeHull.buildHull(convexHullShape.getMargin());

		m_collisionShape = std::make_unique<btConvexHullShape>();
		btConvexHullShape* simpleConvexShape = dynamic_cast<btConvexHullShape*>(m_collisionShape.get());

		const int numVertices = shapeHull.numVertices();
		for (int i = 0; i < numVertices; ++i)
		{
			simpleConvexShape->addPoint(shapeHull.getVertexPointer()[i], false);
		}

		simpleConvexShape->recalcLocalAabb();
	}
}
