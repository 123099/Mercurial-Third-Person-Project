#pragma once
#include <Utils\InstanceCache.hpp>
#include <GL/glew.h>
#include <string>

class Texture : public ICacheable
{
public:
	static Texture* Load(const std::string& name, bool useFullPath = true);

	GLuint GetID();

	virtual void Bind(GLuint textureUnit = 0);
	virtual void Unbind(GLuint textureUnit = 0);

	virtual ~Texture();
protected:
	static InstanceCache<Texture> s_textureCache;
    static Texture* LoadFromFile(const std::string& name);

	Texture(const std::string& name);

	GLuint m_ID;
};