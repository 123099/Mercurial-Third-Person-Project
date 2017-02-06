#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <memory>
#include <GL/glew.h>
#include <Utils\InstanceCache.hpp>

class Texture : public ICacheable
{
public:
	static Texture* Load(const std::string& name);

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

#endif // TEXTURE_H
