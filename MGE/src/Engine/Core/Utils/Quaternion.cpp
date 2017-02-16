#include <Utils\Quaternion.hpp>
#include <bullet\LinearMath\btMatrix3x3.h>

Quaternion Quaternion::Mat4(glm::mat4 mat4)
{
	return Quaternion(glm::quat_cast(mat4));
}

Quaternion Quaternion::EulerAngles(glm::vec3 eulerAngles)
{
	return Quaternion::EulerAngles(eulerAngles.x, eulerAngles.y, eulerAngles.z);
}

Quaternion Quaternion::EulerAngles(float x, float y, float z)
{
	return glm::quat(glm::vec3(glm::radians(x), glm::radians(y), glm::radians(z)));
}

Quaternion::Quaternion(const btQuaternion & quat) 
{
	btMatrix3x3 matrix;
	matrix.setRotation(quat);
	float yaw, pitch, roll;
	matrix.getEulerYPR(yaw, pitch, roll);
	m_quaternion = EulerAngles(glm::vec3(pitch, yaw, roll));
}

Quaternion::Quaternion(const glm::quat & quat) : m_quaternion(quat), euler(GetEulerAngles()) {}

Quaternion::Quaternion(float x, float y, float z, float w) : m_quaternion(w, x, y, z), euler(GetEulerAngles()) {}

void Quaternion::Set(float x, float y, float z, float w)
{
	m_quaternion.x = x;
	m_quaternion.y = y;
	m_quaternion.z = z;
	m_quaternion.w = w;
}

float Quaternion::GetX()
{
	return m_quaternion.x;
}

float Quaternion::GetY()
{
	return m_quaternion.y;
}

float Quaternion::GetZ()
{
	return m_quaternion.z;
}

float Quaternion::GetW()
{
	return m_quaternion.w;
}

Quaternion Quaternion::Inverse()
{
	return glm::inverse(m_quaternion);
}

Quaternion Quaternion::Conjugate()
{
	return glm::conjugate(m_quaternion);
}

glm::vec3 Quaternion::GetEulerAngles() const
{
	const glm::vec3 radians = glm::eulerAngles(m_quaternion);
	return glm::vec3(glm::degrees(radians.x), glm::degrees(radians.y), glm::degrees(radians.z));
}

glm::mat4 Quaternion::ToMat4()
{
	return glm::mat4_cast(m_quaternion);
}

Quaternion::operator glm::quat()
{
	return m_quaternion;
}

Quaternion::operator btQuaternion()
{
	const glm::vec3 euler = GetEulerAngles();
	return btQuaternion(glm::radians(euler.y), glm::radians(euler.x), glm::radians(euler.z));
}
