#include "Terrain.hpp"
#include <Core\GameObject.hpp>
#include <Core\Mesh.hpp>
#include <Utils\glm.hpp>
#include <vector>

Terrain::Terrain() :
	m_width(512),
	m_depth(512),
	m_height(512)
{
}

void Terrain::Awake()
{
	m_meshRenderer = m_gameObject->GetBehaviour<MeshRenderer>();
	SetHeight(m_height);
	RecalculateMesh();
}

void Terrain::RecalculateMesh()
{
	if (m_meshRenderer == nullptr)
	{
		return;
	}

	//Generate vertices and uvs, with top left as the origin
	const int horizontalVertexCount = m_width + 1;
	const int verticalVertexCount = m_depth + 1;
	std::vector<glm::vec3> vertices(horizontalVertexCount * verticalVertexCount);
	std::vector<glm::vec2> uvs(vertices.size());

	//Both loops include the limiter value since we need to generate the closing vertex of the shape as well
	for (int z = 0; z <= m_depth; ++z)
	{
		const int totalColumns = z * horizontalVertexCount;
		for (int x = 0; x <= m_width; ++x)
		{
			vertices[totalColumns + x] = glm::vec3(x, 0, z);
			uvs[totalColumns + x] = glm::vec2((float)x / m_width, (float)z / m_depth);
		}
	}

	//Generate indices for triangels
	std::vector<size_t> triangles(m_width * m_depth * 6);

	int index = 0;
	for (int z = 0; z < m_depth; ++z)
	{
		for (int x = 0; x < m_width; ++x)
		{
			const int firstVertex = z * horizontalVertexCount + x;
			const int firstVertexNextRow = (z + 1) * horizontalVertexCount + x;
			triangles[index] = firstVertex; ++index;
			triangles[index] = firstVertexNextRow; ++index;
			triangles[index] = firstVertexNextRow + 1; ++index;
			triangles[index] = firstVertexNextRow + 1; ++index;
			triangles[index] = firstVertex + 1; ++index;
			triangles[index] = firstVertex; ++index;
		}
	}

	//If the mesh doesn't exist, create one
	if (m_meshRenderer->GetMesh() == nullptr)
	{
		m_meshRenderer->SetMesh(new Mesh("Terrain"));
	}

	//Set the mesh data
	m_meshRenderer->GetMesh()->SetVertices(vertices);
	m_meshRenderer->GetMesh()->SetUVs(uvs);
	m_meshRenderer->GetMesh()->SetTriangles(triangles);

	m_meshRenderer->GetMesh()->UploadMeshData();
}

int Terrain::GetHeight()
{
	return m_height;
}

int Terrain::GetWidth()
{
	return m_width;
}

int Terrain::GetDepth()
{
	return m_depth;
}

void Terrain::SetHeight(int height)
{
	m_height = height;
	if (m_meshRenderer != nullptr && m_meshRenderer->GetSharedMaterial() != nullptr)
	{
		m_meshRenderer->GetSharedMaterial()->SetInteger("maxHeight", m_height);
	}
}

void Terrain::SetWidth(int width)
{
	m_width = width;
	RecalculateMesh();
}

void Terrain::SetDepth(int depth)
{
	m_depth = depth;
	RecalculateMesh();
}

void Terrain::SetSize(int width, int depth)
{
	m_width = width;
	m_depth = depth;
	RecalculateMesh();
}
