#include <Game\Behaviours\LookAt.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <Utils\glm.hpp>

void LookAt::Update()
{
    glm::vec3 forward = glm::normalize(m_gameObject->GetTransform()->GetLocalPosition() - m_target->GetTransform()->GetLocalPosition());
    glm::vec3 right = glm::cross (glm::vec3(0,1,0), forward);
    glm::vec3 up = glm::cross (forward, right);

    m_gameObject->GetTransform()->SetModelMatrix(
      glm::mat4 (glm::vec4(right,0), glm::vec4(up,0), glm::vec4(forward,0), glm::vec4(m_gameObject->GetTransform()->GetLocalPosition(),1) )
    );
}

void LookAt::SetTarget(GameObject * target)
{
}
