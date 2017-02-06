#ifndef KEYSBEHAVIOUR_H
#define KEYSBEHAVIOUR_H

#include <Behaviours\AbstractBehaviour.hpp>

/**
 * KeysBehaviour allows you to move an object using the keyboard in its own local space.
 * Left right turns, forward back moves.
 */
class KeysBehaviour final : public AbstractBehaviour
{
public:
	void SetMoveSpeed(float moveSpeed);
	void SetTurnSpeed(float turnSpeed);

	void Update() override final;
private:
    float m_moveSpeed;
    float m_turnSpeed;
};

#endif // KEYSBEHAVIOUR_H
