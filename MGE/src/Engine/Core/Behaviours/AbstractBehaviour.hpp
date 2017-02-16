#pragma once

class GameObject;

/**
 * An AbstractBehaviour allows you to attach reusable behaviours to GameObjects (Steering, rotating, billboarding, etc).
 * A Behaviour is set on a GameObject, which in turn passes in a reference to itself through the SetGameObject method.
 * This way we can enforce that a Behaviour can never have an owner different from the object it has been attached to.
 */
class AbstractBehaviour
{
friend GameObject;

public:
	AbstractBehaviour();
	virtual ~AbstractBehaviour() = 0;

	GameObject* GetGameObject() const;

	virtual void Awake() {}
	virtual void Start() {}
	virtual void FixedUpdate() {}
	virtual void Update() {}
protected:
	GameObject* m_gameObject;
private:
    void SetGameObject (GameObject* gameObject);

    AbstractBehaviour(const AbstractBehaviour&) = delete;
    AbstractBehaviour& operator=(const AbstractBehaviour&) = delete;
};
