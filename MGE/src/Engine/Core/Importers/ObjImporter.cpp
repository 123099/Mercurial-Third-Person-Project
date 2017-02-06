#include "ObjImporter.hpp"
#include <Core\config.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Utils\glm.hpp>
#include <vector>
#include <algorithm>
#include <map>

Mesh* ObjImporter::LoadObj(const std::string & modelName)
{
	const std::string modelFile = modelName + ".obj";

	//Check if the mesh exists in the cache
	if (Mesh::GetCache().HasValue(modelFile) == true)
	{
		//Return the cached value
		return Mesh::GetCache().GetValue(modelFile);
	}

	std::cout << "Loading " << config::MGE_MODELS_PATH << modelFile << "... ";

	//Open an input file stream
	std::ifstream file(config::MGE_MODELS_PATH + modelFile, std::ios::in);

	//Make sure the file was opened successfully
	if (file.is_open()) 
	{
		//Create a mesh named after the file name
		std::unique_ptr<Mesh> mesh = std::make_unique<Mesh>(modelFile);

		//These three vectors will contains data as taken from the obj file
		//in the order it is encountered in the object file
		std::vector<glm::vec3> tempVertices;
		std::vector<glm::vec3> tempNormals;
		std::vector<glm::vec2> tempUVs;

		//in addition we create a map to store the triplets found under the f(aces) section in the
		//object file and map them to an index for our index buffer (just number them sequentially
		//as we encounter them and store references to the pack
		std::vector<FaceIndexTriplet> indexTriplets;

		//Start reading the file line by line
		std::string command;
		int lineNumber = 1;
		while (file >> command)
		{
			bool success = true;

			if (command == "v")
			{
				glm::vec3 vertex;

				//Read the vertex coordinates
				if (file >> vertex.x >> vertex.y >> vertex.z)
				{
					//Store the vector in the vertices list
					tempVertices.push_back(vertex);
				}
				else
				{
					success = false;
				}
			}
			else if (command == "vt")
			{
				glm::vec2 uv;

				//Read the uv coordinates
				if (file >> uv.x >> uv.y)
				{
					//Store the uv in the uvs list
					tempUVs.push_back(uv);
				}
				else 
				{
					success = false;
				}
			}
			else if (command == "vn")
			{
				glm::vec3 normal;

				//Read the normal coordinates
				if (file >> normal.x >> normal.y >> normal.z)
				{
					//Store the normal in the normals list
					tempNormals.push_back(normal);
				}
				else
				{
					success = false;
				}
			}
			else if (command == "f")
			{
				//Vectors that will store the face indices for the vertices, normals and uvs
				glm::ivec3 vertexIndex;
				glm::ivec3 normalIndex;
				glm::ivec3 uvIndex;

				//Create a string to store the line containing the values
				//We need to retrieve the line as a whole since we are using a non-default delimitier ('/')
				std::string commandline;

				//Read the command line
				std::getline(file, commandline);

				//Replace all the '/' with spaces
				std::replace(commandline.begin(), commandline.end(), '/', ' ');

				//Create a string stream which will parse the line
				std::stringstream stringstream(commandline);

				//Read the face values, with each coordinate of each vector storing 1 point of a triangle
				if (stringstream >>
					vertexIndex.x >> uvIndex.x >> normalIndex.x >>
					vertexIndex.y >> uvIndex.y >> normalIndex.y >>
					vertexIndex.z >> uvIndex.z >> normalIndex.z)
				{
					//Create 3 triplets to form a triangle described by the face indices and store them in the triplets list for later processing
					for (int i = 0; i < 3; ++i)
					{
						FaceIndexTriplet triplet(vertexIndex[i], uvIndex[i], normalIndex[i]);
						indexTriplets.push_back(triplet);
					}
				}
				else
				{
					success = false;
				}
			}
			else
			{
				//The encountered command is not supported. Skip the line
				file.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			}

			if (success == false)
			{
				std::cerr << "[Error] reading obj file " << modelFile << " at line " << lineNumber << ". Number of elements doesn't coincide with what is required.\n";
				return nullptr;
			}

			++lineNumber;
		}

		//Create lists to store index-organized data of the temp loaded data
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		std::vector<GLuint> indices;

		//Process the face triplets to organize the data lists according the triplet indices
		const size_t tripletsCount = indexTriplets.size();
		for (size_t i = 0; i < tripletsCount; ++i)
		{
			FaceIndexTriplet triplet = indexTriplets[i];

			//Push the index of the element for OpenGL
			indices.push_back(i);

			//Push the vertex corresponding to the index stated in the triplet, subtracting 1 to account for obj indices starting from 1
			vertices.push_back(tempVertices[triplet.vertex - 1]);

			//Push the normal corresponding to the index stated in the triplet, subtracting 1 to account for obj indices starting from 1
			normals.push_back(tempNormals[triplet.normal - 1]);

			//Push the uv corresponding to the index stated in the triplet, subtracting 1 to account for obj indices starting from 1
			uvs.push_back(tempUVs[triplet.uv - 1]);
		}

		//Set the data to the mesh
		mesh->SetVertices(vertices);
		mesh->SetNormals(normals);
		mesh->SetUVs(uvs);
		mesh->SetTriangles(indices);
		mesh->CalculateTangents();

		//Buffer the data to OpenGL
		mesh->UploadMeshData();

		//Close the file stream
		file.close();

		std::cout << "Mesh (" << modelFile << ") loaded and buffered: " << (mesh->GetTriangles().size() / 3.0f) << " triangles." << '\n';

		//Add mesh to the cache
		Mesh::GetCache().AddValue(mesh.get());

		return mesh.release();
	}
	else 
	{
		std::cout << "[Error] Could not open OBJ file " << modelFile << '\n';
		return nullptr;
	}
}
