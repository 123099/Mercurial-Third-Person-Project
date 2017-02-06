#pragma once
#include <Textures\Texture.hpp>
#include <string>

class CubeMap : public Texture
{
public:
	enum CubeFace {
		Right,
		Left,
		Top,
		Bottom,
		Back,
		Front
	};

	CubeMap();

	void SetCubeFace(CubeFace face, const std::string& faceTextureName);
	void SetCubeFaces(const std::string cubeFaces[]);
	void SetCubeFaces(const std::string& texturesDirPath, const std::string& textureFileExtension);

	virtual void Bind(GLuint textureUnit) override;
	virtual void Unbind(GLuint textureUnit) override;
};

