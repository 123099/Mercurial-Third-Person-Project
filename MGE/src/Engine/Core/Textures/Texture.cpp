#include <Textures\Texture.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

InstanceCache<Texture> Texture::s_textureCache;

Texture::Texture(const std::string& name) 
{
    glGenTextures (1, &m_ID);
	m_name = name;
}

Texture::~Texture()
{
	if(m_ID != -1)
		glDeleteTextures(1, &m_ID);

	s_textureCache.RemoveValue(m_name);
}

GLuint Texture::GetID()
{
	return m_ID;
}

void Texture::Bind(GLuint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::Unbind(GLuint textureUnit)
{
	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture* Texture::Load(const std::string& name)
{
	Texture* texture = nullptr;

	//Check if the texture is cached
   	if (s_textureCache.HasValue(name) == false) 
	{
        texture = LoadFromFile(name);
		if (texture != nullptr)
		{
			std::cout << "Texture " << name << " with ID " << texture->GetID() << " loaded." << '\n';
			std::cout << "Caching texture..." << '\n';
			s_textureCache.AddValue(texture);
		}
    } 

	return s_textureCache.GetValue(name);
}

Texture* Texture::LoadFromFile(const std::string& name)
{
    sf::Image image;
    if (image.loadFromFile(name)) 
	{
        //Normal image 0,0 is top left, but opengl uv 0,0 is bottom left, so we flip the image internally
        image.flipVertically();

        //Create a new Texture and start filling it with data
        Texture* texture = new Texture(name);
		texture->Bind();

		//Textures are assumed to be pre-gamma corrected, hence, the internal format is set to sRGB
		//When read from a shader, OpenGL automatically converts the color from gamma into linear space
        glTexImage2D (GL_TEXTURE_2D, 0, GL_SRGB_ALPHA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		texture->Unbind();
        return texture;
    } 
	else 
	{
        return nullptr;
    }
}










