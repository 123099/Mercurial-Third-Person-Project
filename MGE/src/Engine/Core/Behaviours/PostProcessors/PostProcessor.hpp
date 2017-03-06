#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Textures\RenderTexture.hpp>
#include <Core\Shader.hpp>
#include <Core\Mesh.hpp>
#include <Utils\MeshFactory.hpp>
#include <memory>

class PostProcessor : public AbstractBehaviour
{
public:
	PostProcessor(Shader& shader) : m_shader(shader), m_quad(MeshFactory::Instance().CreateQuad()) {}

	virtual void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) = 0;
protected:
	Shader& m_shader;
	std::unique_ptr<Mesh> m_quad;
};