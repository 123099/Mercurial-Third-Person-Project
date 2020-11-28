#include "TV.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Renderers\Renderer.hpp>

TV::TV() : m_texture(1280, 720) { m_texture.SetBindDepthTexture(false); }

void TV::Awake()
{
	m_camera = m_gameObject->GetTransform()->GetChildAt(0)->GetGameObject()->GetBehaviour<Camera>();
	m_meshRenderer = m_gameObject->GetBehaviour<MeshRenderer>();
	m_meshRenderer->GetMaterial()->SetFloat("materialReflectivity", 0.0f);
}

void TV::Update()
{
	//Render Camera's view to texture
	m_texture.Activate();
	Renderer::Instance().Render(m_camera->GetViewMatrix(), m_camera->GetProjectionMatrix());
	m_texture.Deactivate();

	//Pass texture's color render to the material
	m_meshRenderer->GetMaterial()->SetTexture("diffuseTexture", &m_texture);
}
