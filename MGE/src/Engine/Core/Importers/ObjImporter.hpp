#pragma once
#include <string>
#include <memory>
#include <Core\Mesh.hpp>

class ObjImporter
{
public:
	/**
	* Load reads the obj data into a new mesh using C++ combined with c style coding.
	* The result is an indexed mesh for use with glDrawElements.
	* Expects a obj file with following layout v/vt/vn/f eg
	**/
	static Mesh* LoadObj(const std::string& modelName);

private:
	ObjImporter() = default;

	struct FaceIndexTriplet 
	{
		GLuint vertex;
		GLuint uv;
		GLuint normal;

		FaceIndexTriplet(GLuint vertex, GLuint uv, GLuint normal) : vertex(vertex), uv(uv), normal(normal) {}
	};
};

