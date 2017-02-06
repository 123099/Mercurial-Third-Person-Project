#pragma once
#include <Utils\glm.hpp>
#include <string>
#include <sstream>
#include <algorithm>
#include <Textures\Texture.hpp>

enum struct PropertyType 
{
	Integer,
	Float,
	Matrix,
	Texture,
	Vector
};

struct ShaderProperty 
{
	std::string name;
	PropertyType type;

	union {
		int intValue;
		float floatValue;
		glm::mat4 matrixValue;
		glm::vec4 vectorValue;
		Texture* textureValue;
	};
	
	ShaderProperty(std::string pName, int value) : name(pName), type(PropertyType::Integer), intValue(value) {}
	ShaderProperty(std::string pName, float value) : name(pName), type(PropertyType::Float), floatValue(value) {}
	ShaderProperty(std::string pName, glm::mat4 value) : name(pName), type(PropertyType::Matrix), matrixValue(value) {}
	ShaderProperty(std::string pName, Texture* value) : name(pName), type(PropertyType::Texture), textureValue(value) {}
	ShaderProperty(std::string pName, glm::vec4 value) : name(pName), type(PropertyType::Vector), vectorValue(value) {}

	friend std::ostream& operator << (std::ostream& out, const ShaderProperty& property)
	{
		out << property.name << " ";

		switch (property.type)
		{
		case PropertyType::Integer:
			out << "integer " << std::to_string(property.intValue);
			break;
		case PropertyType::Float:
			out << "float " << std::to_string(property.floatValue);
			break;
		case PropertyType::Matrix:
		{
			std::stringstream stringstream;
			stringstream << property.matrixValue;
			std::string str = stringstream.str();
			std::replace(str.begin(), str.end(), '\n', ' ');
			out << "matrix " << str;
		}
			break;
		case PropertyType::Texture:
			out << "texture " << property.textureValue->GetName();
			break;
		case PropertyType::Vector:
			out << "vector " <<
				property.vectorValue.x << " " << 
				property.vectorValue.y << " " <<
				property.vectorValue.z << " " <<
				property.vectorValue.w;
			break;
		}

		return out;
	}
};