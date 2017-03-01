#include <Behaviours\Transform.hpp>
#include <Core\GameObject.hpp>
#include <Managers\SceneManager.hpp>
#include <Core\Scene.hpp>
#include <glm\gtx\matrix_decompose.hpp>
#include <algorithm>

Transform::Transform() :
	m_localPosition(glm::vec3(0.0f)),
	m_localRotation(glm::quat()),
	m_localScale(glm::vec3(1.0f)),
	m_cachedModelMatrix(false),
	m_isStatic(false)
{}

Transform::~Transform()
{
	m_parent = nullptr;

	//Destroy all the children
	for (const Transform* child : m_children)
	{
		if (child->GetGameObject() != nullptr)
		{
			SceneManager::Instance().GetActiveScene()->DestroyGameObject(child->GetGameObject());
		}
	}

	m_children.clear();
}

void Transform::SetLocalPosition(const glm::vec3 & position)
{
	//If the transform is static, it is not allowed to move
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot move!" << '\n';
		return;
	}

	m_localPosition = position;
}

void Transform::SetWorldPosition(const glm::vec3 & position)
{
	//If the transform is static, it is not allowed to move
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot move!" << '\n';
		return;
	}

	m_localPosition = position;

	//Go through all the parents until the root parent and subtract their positions
	Transform* currentParent = m_parent;
	while (currentParent != nullptr)
	{
		m_localPosition -= currentParent->m_localPosition;
		currentParent = currentParent->m_parent;
	}
}

void Transform::SetLocalRotation(const Quaternion & rotation)
{
	//If the transform is static, it is not allowed to rotate
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot rotate!" << '\n';
		return;
	}

	m_localRotation = rotation;
}

void Transform::SetWorldRotation(const Quaternion & rotation)
{
	//If the transform is static, it is not allowed to rotate
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot rotate!" << '\n';
		return;
	}

	m_localRotation = rotation;

	//Go through all the parents until the root parent and subtract their rotations
	Transform* currentParent = m_parent;
	while (currentParent != nullptr)
	{
		m_localRotation = currentParent->m_localRotation.Inverse() * m_localRotation;
		currentParent = currentParent->m_parent;
	}
}

void Transform::SetLocalScale(const glm::vec3 & scale)
{
	//If the transform is static, it is not allowed to scale
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot be scaled!" << '\n';
		return;
	}

	m_localScale = scale;
}

glm::vec3 Transform::GetLocalPosition() const
{
	return m_localPosition;
}

glm::vec3 Transform::GetWorldPosition() const
{
	glm::vec3 position = m_localPosition;

	//Go through all the parents until the root parent and add their positions together
	Transform* currentParent = m_parent;
	while (currentParent != nullptr)
	{
		position += currentParent->m_localPosition;
		currentParent = currentParent->m_parent;
	}

	return position;
}

Quaternion Transform::GetLocalRotation() const
{
	return m_localRotation;
}

Quaternion Transform::GetWorldRotation() const
{
	Quaternion rotation = m_localRotation;

	//Go through all the parents until the root parent and add their rotations together
	Transform* currentParent = m_parent;
	while (currentParent != nullptr)
	{
		rotation = currentParent->m_localRotation * rotation;
		currentParent = currentParent->m_parent;
	}

	return rotation;
}

glm::vec3 Transform::GetLocalScale() const
{
	return m_localScale;
}

glm::vec3 Transform::GetLossyWorldScale() const
{
	glm::vec3 lossyScale = m_localScale;

	//Go through all the parents until the root parent and multiply their scales together
	Transform* currentParent = m_parent;
	while (currentParent != nullptr)
	{
		lossyScale *= currentParent->m_localScale;
		currentParent = currentParent->m_parent;
	}

	return lossyScale;
}

glm::vec3 Transform::GetForwardVector() const
{
	return glm::normalize(m_localRotation * glm::vec3(0, 0, -1));
}

glm::vec3 Transform::GetRightVector() const
{
	return glm::normalize(m_localRotation * glm::vec3(1, 0, 0));
}

glm::vec3 Transform::GetUpVector() const
{
	return glm::normalize(m_localRotation * glm::vec3(0, 1, 0));
}

glm::vec3 Transform::GetEulerAngles() const
{
	return m_localRotation.GetEulerAngles();
}

void Transform::SetModelMatrix(const glm::mat4 & matrix, bool worldMatrix)
{
	//If the transform is static, it is not allowed to change its matrix
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot update its matrix!" << '\n';
		return;
	}

	//Decompose the matrix
	glm::vec3 translation;
	glm::quat orientation;
	glm::vec3 scale;
	glm::vec3 skew;
	glm::vec4 perspective;
	glm::decompose(matrix, scale, orientation, translation, skew, perspective);

	Quaternion rotation(glm::conjugate(orientation));
	//std::cout << "--------------" << rotation.GetEulerAngles() << '\n';

	if (worldMatrix == true)
	{
		SetWorldPosition(translation);
		SetWorldRotation(glm::conjugate(orientation));
	}
	else
	{
		SetLocalPosition(translation);
		SetLocalRotation(glm::conjugate(orientation));
	}
	SetLocalScale(scale);

	//Cache the new matrix
	m_modelMatrix = worldMatrix ? matrix : GetModelMatrix();
	m_cachedModelMatrix = true;
}

glm::mat4 Transform::GetModelMatrix()
{
	//If the transform is static, that means that the model matrix isn't going to change, so return the cached value
	if (m_isStatic == true && m_cachedModelMatrix == true)
	{
		return m_modelMatrix;
	}
	else
	{
		//Calculate the TRS matrix based on our local position, rotation and scale
		glm::mat4 TRS = glm::translate(m_localPosition) * m_localRotation.ToMat4() * glm::scale(m_localScale);
		
		//If there is no parent, our matrix is the model to world matrix
		//Otherwise, apply the world transformation of the parentto our TRS matrix
		if(m_parent != nullptr)
		{
			TRS = m_parent->GetModelMatrix() * TRS;
		}

		//Cache the calculated model matrix
		m_modelMatrix = TRS;

		//Mark that we cached the matrix
		m_cachedModelMatrix = true;

		//Return the matrix
		return m_modelMatrix;
	}
}

void Transform::Translate(glm::vec3 translation, Space relativeTo)
{
	switch (relativeTo)
	{
	case Space::Self:
		SetLocalPosition(m_localPosition + m_localRotation * translation);
		break;
	case Space::World:
		SetLocalPosition(m_localPosition + translation);
		break;
	}
}

void Transform::Rotate(glm::vec3 eulerAngles, Space relativeTo)
{
	switch (relativeTo)
	{
	case Space::World:
		SetWorldRotation(Quaternion::EulerAngles(eulerAngles) * GetWorldRotation());
		break;
	case Space::Self:
		SetLocalRotation(Quaternion::EulerAngles(eulerAngles) * m_localRotation);
		break;
	}
}

void Transform::RotateAround(float angle, glm::vec3 axis)
{
	RotateAround(glm::vec3(0.0f), angle, axis);
}

void Transform::RotateAround(glm::vec3 pivot, float angle, glm::vec3 axis)
{
	glm::quat rotation = glm::angleAxis(glm::radians(angle), axis);
	SetLocalPosition(rotation * (m_localPosition - pivot) + pivot);
	SetLocalRotation(rotation * m_localRotation);
}

void Transform::SetStatic(bool isStatic, bool changeChildren)
{
	m_isStatic = isStatic;

	if (changeChildren == true)
	{
		const auto children = GetAllChildrenRecursively();
		for (auto& child : children)
		{
			child->SetStatic(isStatic);
		}
	}
}

bool Transform::IsStatic() const
{
	return m_isStatic;
}

void Transform::SetParent(Transform * parent, bool worldPositionStays)
{
	//If the transform is static, it is not allowed to change its parent, since that would imply a different world matrix
	if (m_isStatic == true)
	{
		std::cerr << "Transform marked as static cannot change its parent!" << '\n';
		return;
	}

	//Remove from previous parent
	if (m_parent != nullptr)
	{
		//Scan the children to find ourselves, and remove it from the vector
		m_parent->m_children.erase(std::remove(m_parent->m_children.begin(), m_parent->m_children.end(), this));
	}

	if (worldPositionStays == true)
	{
		//When setting a parent, the local transform should become the world transform
		//When removing a parent, the world transform should become the local transform

		//If there was a parent, this is world transform. If there wasn't, this is local transform
		const glm::mat4 modelMatrix = GetModelMatrix();

		//Set the new parent
		m_parent = parent;

		//Apply the model matrix
		SetModelMatrix(modelMatrix);
	}
	else
	{
		//Set the new parent
		m_parent = parent;
	}

	if (m_gameObject != nullptr)
	{
		if (m_parent == nullptr)
		{
			//Add the game object to the scene root list
			SceneManager::Instance().GetActiveScene()->AddToRoot(m_gameObject);
		}
		else
		{
			//Remove the game object from the scene root list
			SceneManager::Instance().GetActiveScene()->RemoveFromRoot(m_gameObject);

			//Add ourselves as child of the parent
			m_parent->m_children.push_back(this);
		}
	}
}

Transform * Transform::GetParent() const
{
	return m_parent;
}

Transform * Transform::GetRoot()
{
	if (m_parent == nullptr)
	{
		return this;
	}
	else
	{
		return m_parent->GetRoot();
	}
}

Transform * Transform::GetChildAt(int index) const
{
	return m_children[index];
}

int Transform::GetChildCount() const
{
	return m_children.size();
}

std::vector<Transform*> Transform::GetAllChildrenRecursively() const
{
	std::vector<Transform*> totalChildren;

	for (auto& child : m_children)
	{
		totalChildren.push_back(child);

		if (child->GetChildCount() > 0)
		{
			const auto childChildren = child->GetAllChildrenRecursively();
			totalChildren.insert(totalChildren.end(), childChildren.begin(), childChildren.end());
		}
	}

	return totalChildren;
}
