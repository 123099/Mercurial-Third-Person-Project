#ifndef ROTATINGBEHAVIOUR_H
#define ROTATINGBEHAVIOUR_H

#include <Behaviours\AbstractBehaviour.hpp>

/**
 * Simply rotates the object around its origin
 */
class RotatingBehaviour final : public AbstractBehaviour
{
public:
	void SetSpeed(float speed);

	void Update() override final;
private:
	float m_speed;
};

#endif // ROTATINGBEHAVIOUR_H
