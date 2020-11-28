#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Game\Behaviours\TranslationAnimation.hpp>

class Door final : public AbstractBehaviour
{
public:
	void Awake() override final;

	void Open();
	void Close();

	bool IsOpen();
	bool IsMoving();
private:
	TranslationAnimation* m_leftPart;
	TranslationAnimation* m_rightPart;

	bool m_isOpen;
	glm::vec3 m_rightDirection;

	void Move();
};