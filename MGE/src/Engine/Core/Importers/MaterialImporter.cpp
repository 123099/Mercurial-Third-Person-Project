#include "MaterialImporter.hpp"
#include <fstream>
#include <memory>
#include <Core\config.hpp>
#include <Utils\Debug.hpp>

Material* MaterialImporter::LoadMaterial(const std::string & materialName)
{
	//Check if the material is in the cache
	if (Material::GetCache().HasValue(materialName) == true)
	{
		//Return the cached material
		return Material::GetCache().GetValue(materialName);
	}

	//Open an input file stream
	std::ifstream file(config::MGE_MATERIALS_PATH + materialName + ".mat");

	//Make sure that we managed to open the file
	if (file.is_open())
	{
		std::unique_ptr<Material> material;

		//Start reading the file, line by line
		int lineNumber = 1;
		std::string property;
		while (file >> property)
		{
			if (property[0] == '#')
			{
				//Ignore the line
				file.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				++lineNumber;
				continue;
			}

			std::string definition;
			if (file >> definition)
			{
				bool success = true;

				if (property == "shader")
				{
					material = std::make_unique<Material>(Shader::Find(definition), materialName);
				}
				else if (material != nullptr)
				{
					if (definition == "integer" || definition == "int")
					{
						int value;
						if (file >> value)
						{
							material->SetInteger(property, value);
						}
						else
						{
							success = false;
						}
					}
					else if (definition == "float")
					{
						float value;
						if (file >> value)
						{
							material->SetFloat(property, value);
						}
						else
						{
							success = false;
						}
					}
					else if (definition == "matrix" || definition == "mat")
					{
						//[col][row]
						glm::mat4 value;
						if (file >>
							value[0][0] >> value[1][0] >> value[2][0] >> value[3][0] >>
							value[0][1] >> value[1][1] >> value[2][1] >> value[3][1] >>
							value[0][2] >> value[1][2] >> value[2][2] >> value[3][2] >>
							value[0][3] >> value[1][3] >> value[2][3] >> value[3][3])
						{
							material->SetMatrix(property, value);
						}
						else
						{
							success = false;
						}
					}
					else if (definition == "texture")
					{
						std::string value;
						if (file >> value)
						{
							//Load the texture
							Texture* texture = Texture::Load(value);

							//Check if the texture loaded successfully
							if (texture != nullptr)
							{
								//Apply the property to the material
								material->SetTexture(property, texture);
							}
							else
							{
								Debug::Instance().LogError("While loading material " + materialName + ": Failed to load texture " + property + " from " + value);
							}
						}
						else
						{
							success = false;
						}
					}
					else if (definition == "vector" || definition == "color")
					{
						glm::vec4 value;
						if (file >> value.x >> value.y >> value.z >> value.w)
						{
							if (definition == "vector")
							{
								material->SetVector(property, value);
							}
							else if (definition == "color")
							{
								material->SetColor(property, value);
							}
						}
						else
						{
							success = false;
						}
					}
					else
					{
						Debug::Instance().LogWarning("While loading material " + materialName + ": Unknown type " + definition + " on line " + std::to_string(lineNumber));
					}
				}
				else 
				{
					Debug::Instance().LogError("Bad material file format. First line must start with the word 'shader' and define the name of the shader to use!");
					return nullptr;
				}

				if (success == false)
				{
					Debug::Instance().LogError("While loading material " + materialName + ": Failed to read property " + property);
				}

				++lineNumber;
			}
			else
			{
				Debug::Instance().LogError("Bad material file format. First line must start with the word 'shader' and define the name of the shader to use!");
				return nullptr;
			}
		}

		//Close the stream
		file.close();

		Debug::Instance().LogSuccess("Material " + materialName + " loaded successfully!");

		//Add the material to the cache
		Material::GetCache().AddValue(material.get());

		//Return the material
		return material.release();
	}
	else
	{
		Debug::Instance().LogError("Failed to open material file " + materialName + ".mat");
		return nullptr;
	}
}
