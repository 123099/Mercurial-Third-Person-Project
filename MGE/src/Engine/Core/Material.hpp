#pragma once

#include <string>
#include <unordered_map>
#include <Utils\glm.hpp>
#include <memory>
#include <Core\Shader.hpp>
#include <Managers\Renderer.hpp>
#include <Utils\InstanceCache.hpp>

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

    virtual void Render(Mesh* mesh, const glm::mat4& modelMatrix, const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix, const glm::mat4& viewProjectionMatrix);

	void SaveToFile(const std::string& materialName);

private:
	static InstanceCache<Material> s_materialCache;

	Shader& m_shader;
	int m_setTextureCount;
	
	std::unordered_map<std::string, ShaderProperty*> m_shaderProperties;

	void SetProperty(ShaderProperty& property);
	ShaderProperty* GetProperty(const std::string& propertyName);
	bool HasProperty(const std::string& propertyName);

	bool CanBindExtraTexture();
};
