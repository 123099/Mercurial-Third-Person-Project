#pragma once

#include <string>
#include <unordered_map>
#include <Utils\glm.hpp>
#include <Core\Shader.hpp>
#include <Renderers\Renderer.hpp>
#include <Utils\InstanceCache.hpp>
#include <memory>

class Mesh;

class Material final : public ICacheable
{
public:
	static InstanceCache<Material>& GetCache();

    Material(Shader* shader, const std::string& name = "New Material");

	void SetInteger(const std::string& propertyName, int value);
	void SetColor(const std::string& propertyName, glm::vec4 color);
	void SetFloat(const std::string& propertyName, float value);
	void SetMatrix(const std::string& propertyName, glm::mat4 matrix);
	void SetVector(const std::string& propertyName, glm::vec4 vector);
	void SetTexture(const std::string& propertyName, Texture* texture);

    void Render(Mesh* mesh, const glm::mat4& modelMatrix, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, const glm::mat4& viewProjectionMatrix, bool simpleRender = false, bool castShadows = true, bool receiveShadows = true);

	void SaveToFile(const std::string& materialName);

private:
	static InstanceCache<Material> s_materialCache;
	static Shader* s_simpleShader;

	Shader& m_shader;
	int m_setTextureCount;
	
	std::unordered_map<std::string, std::shared_ptr<ShaderProperty>> m_shaderProperties;

	void SetProperty(const ShaderProperty& property);
	ShaderProperty* GetProperty(const std::string& propertyName);
	bool HasProperty(const std::string& propertyName);

	bool CanBindExtraTexture();

	void FullRender(Mesh* mesh, const glm::mat4& modelMatrix, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, const glm::mat4& viewProjectionMatrix, bool receiveShadows);
	void SimpleRender(Mesh* mesh, const glm::mat4& modelMatrix, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, const glm::mat4& viewProjectionMatrix, bool castShadows);
};
