#include <Core\Mesh.hpp>
#include <iostream>

InstanceCache<Mesh> Mesh::s_meshCache;

InstanceCache<Mesh>& Mesh::GetCache()
{
	return s_meshCache;
}

Mesh::Mesh(std::string name) :
	m_indexBufferID(-1),
	m_vertexBufferID(-1),
	m_normalBufferID(-1),
	m_uvBufferID(-1),
	m_tangentBufferID(-1) 
{
	m_name = name;
}

Mesh::~Mesh() 
{
	//Delete all the buffers this mesh created on the GPU
	GLuint buffers[5] = {
		m_indexBufferID,
		m_vertexBufferID,
		m_normalBufferID,
		m_uvBufferID,
		m_tangentBufferID
	};
	glDeleteBuffers(5, &buffers[0]);

	//Delete the mesh from the mesh cache
	s_meshCache.RemoveValue(m_name);
}

std::vector<glm::vec3> Mesh::GetVertices()
{
	return m_vertices;
}

std::vector<glm::vec3> Mesh::GetNormals()
{
	return m_normals;
}

std::vector<glm::vec2> Mesh::GetUVs()
{
	return m_uvs;
}

std::vector<size_t> Mesh::GetTriangles()
{
	return m_triangles;
}

void Mesh::SetVertices(std::vector<glm::vec3> vertices)
{
	m_vertices = vertices;
}

void Mesh::SetNormals(std::vector<glm::vec3> normals)
{
	m_normals = normals;
}

void Mesh::SetUVs(std::vector<glm::vec2> uvs)
{
	m_uvs = uvs;
}

void Mesh::SetTriangles(std::vector<size_t> triangles)
{
	//Make sure that the triangle indices count is a multiple of 3
	if (triangles.size() % 3 != 0)
	{
		std::cerr << "Error setting mesh " << m_name << " triangles: Triangle index array has to have a size multiple of three!" << '\n';
	}
	else
	{
		m_triangles = triangles;
	}
}

int Mesh::GetVertexCount()
{
	return m_vertices.size();
}

int Mesh::GetTriangleCount()
{
	return m_triangles.size() / 3;
}

void Mesh::CalculateTangents(bool flipBinormals)
{
	//Clear the tangent array
	m_tangents.clear();

	//Go through all the triangles in the mesh
	for (size_t i = 0; i < m_triangles.size(); i += 3)
	{
		//Retrieve the vertices of the triangle
		glm::vec3& v0 = m_vertices[i];
		glm::vec3& v1 = m_vertices[i + 1];
		glm::vec3& v2 = m_vertices[i + 2];

		//Retrieve the uvs of the triangle
		glm::vec2& uv0 = m_uvs[i];
		glm::vec2& uv1 = m_uvs[i + 1];
		glm::vec2& uv2 = m_uvs[i + 2];

		//Calculate triangle edges
		glm::vec3 edge1 = v1 - v0;
		glm::vec3 edge2 = v2 - v0;

		//Calculate uv direction for the edges
		glm::vec2 deltaUV1 = uv1 - uv0;
		glm::vec2 deltaUV2 = uv2 - uv0;

		//Calculate the 2x2 matrix inverse determinant scalar
		float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);

		//Calculate the tangent
		glm::vec3 tangent = (edge1 * deltaUV2.y - edge2 * deltaUV1.y) * r;

		//Calculate the w component based on the flip variable
		float w = 1;
		if (flipBinormals == true)
		{
			w = -1;
		}

		m_tangents.push_back(glm::vec4(tangent, w));
		m_tangents.push_back(glm::vec4(tangent, w));
		m_tangents.push_back(glm::vec4(tangent, w));
	}
}

void Mesh::UploadMeshData()
{
	Buffer();
}

void Mesh::Buffer()
{
	//Only generate a new buffer if the buffer doesn't exist yet
	//Otherwise, simply bind the buffer index and upload the latest data
	if (m_indexBufferID == -1) glGenBuffers(1, &m_indexBufferID);
	if (m_vertexBufferID == -1) glGenBuffers(1, &m_vertexBufferID);
	if (m_normalBufferID == -1) glGenBuffers(1, &m_normalBufferID);
	if (m_uvBufferID == -1) glGenBuffers(1, &m_uvBufferID);
	if (m_tangentBufferID == -1) glGenBuffers(1, &m_tangentBufferID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_triangles.size()*sizeof(GLuint), &m_triangles[0], GL_STATIC_DRAW);

    glBindBuffer( GL_ARRAY_BUFFER, m_vertexBufferID);
    glBufferData( GL_ARRAY_BUFFER, m_vertices.size()*sizeof(glm::vec3), &m_vertices[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ARRAY_BUFFER, m_normalBufferID );
    glBufferData( GL_ARRAY_BUFFER, m_normals.size()*sizeof(glm::vec3), &m_normals[0], GL_STATIC_DRAW );

    glBindBuffer( GL_ARRAY_BUFFER, m_uvBufferID );
    glBufferData( GL_ARRAY_BUFFER, m_uvs.size()*sizeof(glm::vec2), &m_uvs[0], GL_STATIC_DRAW );

	glBindBuffer(GL_ARRAY_BUFFER, m_tangentBufferID);
	glBufferData(GL_ARRAY_BUFFER, m_tangents.size() * sizeof(glm::vec4), &m_tangents[0], GL_STATIC_DRAW);

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void Mesh::StreamToOpenGL(GLint verticesAttrib, GLint normalsAttrib, GLint UVsAttrib, GLint tangentsAttrib) {
    if (verticesAttrib != -1) 
	{
        glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
        glEnableVertexAttribArray(verticesAttrib);
        glVertexAttribPointer(verticesAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0 );
    }

    if (normalsAttrib != -1) 
	{
        glBindBuffer( GL_ARRAY_BUFFER, m_normalBufferID);
        glEnableVertexAttribArray(normalsAttrib);
        glVertexAttribPointer(normalsAttrib, 3, GL_FLOAT, GL_TRUE, 0, 0 );
    }

    if (UVsAttrib != -1) 
	{
        glBindBuffer( GL_ARRAY_BUFFER, m_uvBufferID);
        glEnableVertexAttribArray(UVsAttrib);
        glVertexAttribPointer(UVsAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }

	if (tangentsAttrib != -1)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_tangentBufferID);
		glEnableVertexAttribArray(tangentsAttrib);
		glVertexAttribPointer(tangentsAttrib, 4, GL_FLOAT, GL_FALSE, 0, 0);
	}

	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID );

	glDrawElements(GL_TRIANGLES, m_triangles.size(), GL_UNSIGNED_INT, (GLvoid*)0);

	//Unbind the buffers to avoid mishaps. Very important for performance
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//Disable the VAOs so that the next mesh rendered doesn't use them when drawing
	if (UVsAttrib != -1) glDisableVertexAttribArray(UVsAttrib);
	if (normalsAttrib != -1) glDisableVertexAttribArray(normalsAttrib);
	if (verticesAttrib != -1) glDisableVertexAttribArray(verticesAttrib);
	if (tangentsAttrib != -1) glDisableVertexAttribArray(tangentsAttrib);
}

void Mesh::drawDebugInfo(const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
    //demo of how to render some debug info using the good ol' direct rendering mode...
    glUseProgram(0);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(pProjectionMatrix));
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(pViewMatrix * pModelMatrix));

    glBegin(GL_LINES);
    //for each index draw the normal starting at the corresponding vertex
    for (size_t i=0; i<m_triangles.size(); i++){
        //draw normal for vertex
        if (true) {
            //now get normal end
            glm::vec3 normal = m_normals[m_triangles[i]];
            glColor3fv(glm::value_ptr(normal));

            glm::vec3 normalStart = m_vertices[m_triangles[i]];
            glVertex3fv(glm::value_ptr(normalStart));
            glm::vec3 normalEnd = normalStart + normal*0.2f;
            glVertex3fv(glm::value_ptr(normalEnd));
        }

    }
    glEnd();
}



