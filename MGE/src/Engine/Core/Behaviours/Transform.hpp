/*
* Possible Optimization:
* Always cache the model matrix
* Update it if the position/rotation/scale has changed
* Update if parent has changed
* Every update iterates over all children and updates them
*/

#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Utils\Quaternion.hpp>
#include <Utils\glm.hpp>
#include <vector>

enum Space {
	Self,
	World
};

class Transform : public AbstractBehaviour
{
public:
	Transform();
	~Transform();

	void SetLocalPosition(const glm::vec3& position);
	void SetWorldPosition(const glm::vec3& position);
	void SetLocalRotation(const Quaternion& rotation);
	void SetWorldRotation(const Quaternion& rotation);
	void SetLocalScale(const glm::vec3& scale);

	glm::vec3 GetLocalPosition() const;
	glm::vec3 GetWorldPosition() const;
	Quaternion GetLocalRotation() const;
	Quaternion GetWorldRotation() const;
	glm::vec3 GetLocalScale() const;
	glm::vec3 GetLossyWorldScale() const;

	glm::vec3 GetForwardVector() const;
	glm::vec3 GetRightVector() const;
	glm::vec3 GetUpVector() const;

	glm::vec3 GetEulerAngles() const;

	void SetModelMatrix(const glm::mat4& matrix, bool worldMatrix = true);
	glm::mat4 GetModelMatrix();

	void Translate(glm::vec3 translation, Space relativeTo = Space::Self);
	void Rotate(glm::vec3 eulerAngles, Space relativeTo = Space::Self);
	void RotateAround(float angle, glm::vec3 axis);
	void RotateAround(glm::vec3 pivot, float angle, glm::vec3 axis);

	void SetStatic(bool isStatic, bool changeChildren = false);
	bool IsStatic() const;

	void SetParent(Transform* parent, bool worldPositionStays = true);
	Transform* GetParent() const;
	Transform* GetRoot();

	int GetChildCount() const;
	Transform* GetChildAt(int index) const;
	std::vector<Transform*> GetAllChildrenRecursively() const;
private:
	Transform* m_parent;
	std::vector<Transform*> m_children;

	glm::vec3 m_localPosition;
	Quaternion m_localRotation;
	glm::vec3 m_localScale;

	glm::mat4 m_modelMatrix;
	bool m_isStatic;
	bool m_cachedModelMatrix;
};