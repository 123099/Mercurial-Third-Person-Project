#include "MeshRenderer.hpp"
#include <Renderers\Renderer.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>

void MeshRenderer::GetTotalVertexTriangleCountInScene(int * vertexCount, int * triangleCount)
{
	const auto& rootGameObjects = SceneManager::Instance().GetActiveScene()->GetRootGameObjects();
	for (const auto& rootGameObject : rootGameObjects)
	{
		auto sceneGraph = rootGameObject->GetTransform()->GetAllChildrenRecursively();
		sceneGraph.push_back(rootGameObject->GetTransform());

		for (Transform* child : sceneGraph)
		{
			if (child->GetGameObject()->GetBehaviour<MeshRenderer>() != nullptr && child->GetGameObject()->GetBehaviour<MeshRenderer>()->GetSharedMesh() != nullptr)
			{
				*vertexCount += child->GetGameObject()->GetBehaviour<MeshRenderer>()->GetSharedMesh()->GetVertexCount();
				*triangleCount += child->GetGameObject()->GetBehaviour<MeshRenderer>()->GetSharedMesh()->GetTriangleCount();
			}
		}
	}
}

MeshRenderer::MeshRenderer() :
	m_sharedMesh(nullptr),
	m_sharedMaterial(nullptr),
	m_meshLinkedToShared(true),
	m_materialLinkedToShared(true)
{
	Renderer::Instance().AddRenderable(this);
}

MeshRenderer::~MeshRenderer()
{
	Renderer::Instance().RemoveRenderable(this);
}

void MeshRenderer::SetMesh(Mesh* mesh)
{
	if (m_meshLinkedToShared == true)
	{
		UnlinkFromSharedMesh();
	}

	delete m_mesh;
	m_mesh = mesh;
}

void MeshRenderer::SetMaterial(Material* material)
{
	if (m_materialLinkedToShared == true)
	{
		UnlinkFromSharedMaterial();
	}

	delete m_material;
	m_material = material;
}

void MeshRenderer::SetSharedMesh(Mesh* sharedMesh)
{
	if (m_meshLinkedToShared == true)
	{
		m_sharedMesh = sharedMesh;
	}
	else
	{
		SetMesh(sharedMesh);
	}
}

void MeshRenderer::SetSharedMaterial(Material* sharedMaterial)
{
	if (m_materialLinkedToShared == true)
	{
		m_sharedMaterial = sharedMaterial;
	}
	else
	{
		SetMaterial(sharedMaterial);
	}
}

Mesh* MeshRenderer::GetMesh()
{
	if (m_meshLinkedToShared == true)
	{
		UnlinkFromSharedMesh();
	}

	return m_mesh;
}

Material* MeshRenderer::GetMaterial()
{
	if (m_materialLinkedToShared == true)
	{
		UnlinkFromSharedMaterial();
	}

	return m_material;
}

Mesh* MeshRenderer::GetSharedMesh()
{
	if (m_meshLinkedToShared == true)
	{
		return m_sharedMesh;
	}
	else
	{
		return m_mesh;
	}
}

Material * MeshRenderer::GetSharedMaterial()
{
	if (m_materialLinkedToShared == true)
	{
		return m_sharedMaterial;
	}
	else
	{
		return m_material;
	}
}

void MeshRenderer::UnlinkFromSharedMesh()
{
	//If the shared mesh hasn't been initialized, we have no data to copy to make an instance from
	//Therefore, create a new empty mesh
	if (m_sharedMesh == nullptr)
	{
		m_mesh = new Mesh("New Mesh");
	}
	else
	{
		//Create a copy of the shared mesh
		m_mesh = new Mesh(*m_sharedMesh);

		//Release the shared mesh pointer since we no longer have a link to it
		m_sharedMesh = nullptr;
	}

	//Mark ourselves as no longer linked to the shared mesh
	//From now on, every call related to sharedMesh acts upon the mesh instance
	m_meshLinkedToShared = false;
}

void MeshRenderer::UnlinkFromSharedMaterial()
{
	//If the shared material hasn't been initialized, we have no data to copy to make an instance from
	//Therefore, create a new empty material
	if (m_sharedMaterial == nullptr)
	{
		m_material = new Material(nullptr);
	}
	else
	{
		//Create a copy of the shared mesh
		m_material = new Material(*m_sharedMaterial);

		//Release the shared mesh pointer since we no longer have a link to it
		m_sharedMaterial = nullptr;
	}

	//Mark ourselves as no longer linked to the shared mesh
	//From now on, every call related to sharedMesh acts upon the mesh instance
	m_materialLinkedToShared = false;
}

void MeshRenderer::Render(const glm::mat4 & viewMatrix, const glm::mat4 & projectionMatrix, const glm::mat4& viewProjectionMatrix, bool simpleRender) const
{
	Mesh* mesh = m_mesh == nullptr ? m_sharedMesh : m_mesh;
	Material* material = m_material == nullptr ? m_sharedMaterial : m_material;

	if (material != nullptr && mesh != nullptr)
	{
		material->Render(mesh, m_gameObject->GetTransform()->GetModelMatrix(), viewMatrix, projectionMatrix, viewProjectionMatrix, simpleRender);
	}
}
