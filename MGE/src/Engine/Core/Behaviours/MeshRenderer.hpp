#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Core\Material.hpp>
#include <Core\Mesh.hpp>
#include <Utils\glm.hpp>

class Renderer;

class MeshRenderer : public AbstractBehaviour, public DisallowMultiple
{
friend Renderer;

public:
	static void GetTotalVertexTriangleCountInScene(int* vertexCount, int* triangleCount);

	MeshRenderer();
	~MeshRenderer() override;

	void SetMesh(Mesh* mesh);
	void SetSharedMesh(Mesh* sharedMesh);
	void SetMaterial(Material* material);
	void SetSharedMaterial(Material* sharedMaterial);

	Mesh* GetMesh();
	Mesh* GetSharedMesh();
	Material* GetMaterial();
	Material* GetSharedMaterial();
private:
	Mesh* m_mesh;
	Material* m_material;

	Mesh* m_sharedMesh;
	Material* m_sharedMaterial;

	bool m_meshLinkedToShared;
	bool m_materialLinkedToShared;

	void UnlinkFromSharedMesh();
	void UnlinkFromSharedMaterial();

	void Render(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, const glm::mat4& viewProjectionMatrix, bool simpleRender = false) const;
};

