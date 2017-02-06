#pragma once
#include <Utils\glm.hpp>

class Quaternion final
{
public:
	static Quaternion Mat4(glm::mat4 mat4);
	static Quaternion EulerAngles(glm::vec3 eulerAngles);
	static Quaternion EulerAngles(float x, float y, float z);

	Quaternion(const glm::quat& quat);
	Quaternion(float x, float y, float z, float w);

	void Set(float x, float y, float z, float w);
	float GetX();
	float GetY();
	float GetZ();
	float GetW();

	Quaternion Inverse();
	Quaternion Conjugate();

	glm::vec3 GetEulerAngles() const;
	glm::mat4 ToMat4();

	friend Quaternion operator*(const Quaternion& a, const Quaternion& b);
	friend glm::vec3 operator*(const Quaternion& a, const glm::vec3& b);
private:
	glm::quat m_quaternion;
	glm::vec3 euler;
};

inline Quaternion operator*(const Quaternion& a, const Quaternion& b)
{
	return Quaternion(a.m_quaternion * b.m_quaternion);
}

inline glm::vec3 operator*(const Quaternion& a, const glm::vec3& b)
{
	return a.m_quaternion * b;
}
