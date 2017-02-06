#include "CubeMap.hpp"
#include <SFML\Graphics.hpp>

CubeMap::CubeMap() : Texture("CubeMap")
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void CubeMap::SetCubeFace(CubeFace face, const std::string& faceTextureName)
{
	sf::Image image;
	if (image.loadFromFile(faceTextureName))
	{
		//Following the RenderMan specification for CubeMaps, the image doesn't get flipped on the Y axis, like the usual textures

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + face, 0, GL_SRGB_ALPHA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

		glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	}
}

void CubeMap::SetCubeFaces(const std::string cubeFaces[])
{
	for (int i = 0; i < 6; ++i)
	{
		SetCubeFace((CubeFace)i, cubeFaces[i]);
	}
}

void CubeMap::SetCubeFaces(const std::string & texturesDirPath, const std::string & textureFileExtension)
{
	std::string textures[6] = 
	{
		texturesDirPath + "right" + textureFileExtension,
		texturesDirPath + "left" + textureFileExtension,
		texturesDirPath + "top" + textureFileExtension,
		texturesDirPath + "bottom" + textureFileExtension,
		texturesDirPath + "back" + textureFileExtension,
		texturesDirPath + "front" + textureFileExtension,
	};

	SetCubeFaces(textures);
}

void CubeMap::Bind(GLuint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_ID);
}

void CubeMap::Unbind(GLuint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
