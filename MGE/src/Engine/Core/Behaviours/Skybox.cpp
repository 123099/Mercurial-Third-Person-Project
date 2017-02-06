#include "Skybox.hpp"
#include <vector>
#include <Core\Material.hpp>
#include <Core\Mesh.hpp>
#include <Core\Shader.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Behaviours\Camera.hpp>
#include <Textures\CubeMap.hpp>

static Mesh* CreateInvertedCube();

Skybox::Skybox() : m_tintColor(glm::vec4(0.5, 0.5, 0.5, 1)), m_exposure(1) {}

void Skybox::Awake()
{
	m_meshRenderer = m_gameObject->GetBehaviour<MeshRenderer>();

	m_meshRenderer->SetMesh(CreateInvertedCube());
	m_meshRenderer->SetMaterial(new Material(Shader::Find("unlit/skybox")));

	SetTintColor(m_tintColor);
	SetExposure(m_exposure);
	SetSkyboxCubeMap(m_skyboxCubeMap);
}

void Skybox::SetCamera(Camera * camera)
{
	m_camera = camera;
}

void Skybox::SetTintColor(glm::vec4 tintColor)
{
	m_tintColor = tintColor;
	if (m_meshRenderer != nullptr && m_meshRenderer->GetMaterial() != nullptr)
	{
		m_meshRenderer->GetMaterial()->SetColor("tintColor", m_tintColor);
	}
}

void Skybox::SetExposure(float exposure)
{
	m_exposure = exposure;
	if (m_meshRenderer != nullptr && m_meshRenderer->GetMaterial() != nullptr)
	{
		m_meshRenderer->GetMaterial()->SetFloat("exposure", m_exposure);
	}
}

void Skybox::SetSkyboxCubeMap(CubeMap* skyboxCubeMap)
{
	m_skyboxCubeMap = skyboxCubeMap;
	if (m_meshRenderer != nullptr && m_meshRenderer->GetMaterial() != nullptr)
	{
		m_meshRenderer->GetMaterial()->SetTexture("skybox", m_skyboxCubeMap);
	}
}

void Skybox::Update()
{
	m_gameObject->GetTransform()->SetLocalScale(glm::vec3(m_camera == nullptr ? 500 : m_camera->GetFarPlane() * 0.4f));
}

static Mesh* CreateInvertedCube()
{
	//Define vertices
	std::vector<glm::vec3> vertices;
	vertices.push_back(glm::vec3(-1, -1, 1));
	vertices.push_back(glm::vec3(1, -1, 1));
	vertices.push_back(glm::vec3(1, 1, 1));
	vertices.push_back(glm::vec3(-1, 1, 1));

	vertices.push_back(glm::vec3(-1, -1, -1));
	vertices.push_back(glm::vec3(1, -1, -1));
	vertices.push_back(glm::vec3(1, 1, -1));
	vertices.push_back(glm::vec3(-1, 1, -1));

	//Define triangles
	std::vector<GLuint> triangles;
	triangles.push_back(0); triangles.push_back(3); triangles.push_back(2);
	triangles.push_back(2); triangles.push_back(1); triangles.push_back(0);

	triangles.push_back(1); triangles.push_back(2); triangles.push_back(6);
	triangles.push_back(6); triangles.push_back(5); triangles.push_back(1);

	triangles.push_back(5); triangles.push_back(6); triangles.push_back(4);
	triangles.push_back(4); triangles.push_back(6); triangles.push_back(7);

	triangles.push_back(0); triangles.push_back(4); triangles.push_back(7);
	triangles.push_back(7); triangles.push_back(3); triangles.push_back(0);

	triangles.push_back(3); triangles.push_back(7); triangles.push_back(6);
	triangles.push_back(6); triangles.push_back(2); triangles.push_back(3);

	triangles.push_back(0); triangles.push_back(1); triangles.push_back(5);
	triangles.push_back(5); triangles.push_back(4); triangles.push_back(0);

	//Create Mesh
	Mesh* mesh = new Mesh("Skybox");
	mesh->SetVertices(vertices);
	mesh->SetTriangles(triangles);
	mesh->UploadMeshData();

	return mesh;
}
