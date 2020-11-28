#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Textures\RenderTexture.hpp>
#include <Core\Shader.hpp>
#include <Core\Mesh.hpp>
#include <memory>

class PostProcessor : public AbstractBehaviour
{
public:
	PostProcessor(Shader& shader);
	virtual ~PostProcessor();

	virtual void ProcessTexture(RenderTexture& texture, RenderTexture& originalTexture) = 0;
protected:
	Shader& m_shader;

	void DrawToTexture();
private:
	std::unique_ptr<Mesh> m_quad;
};