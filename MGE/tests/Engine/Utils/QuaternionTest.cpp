#include <gtest\gtest.h>
#include <Utils\Quaternion.hpp>

TEST(QuaternionTest, constructor)
{
	Quaternion q(0.0f, 0.866f, 0.0f, 0.5f);
	EXPECT_NEAR(q.GetX(), 0, 0.01f);
	EXPECT_NEAR(q.GetY(), 0.866, 0.01f);
	EXPECT_NEAR(q.GetZ(), 0, 0.01f);
	EXPECT_NEAR(q.GetW(), 0.5, 0.01f);
}

TEST(QuaternionTest, constructorFromEuler)
{
	Quaternion q = Quaternion::EulerAngles(0, -120, 0);
	EXPECT_NEAR(q.GetX(), 0, 0.01f);
	EXPECT_NEAR(q.GetY(), -0.866, 0.01f);
	EXPECT_NEAR(q.GetZ(), 0, 0.01f);
	EXPECT_NEAR(q.GetW(), 0.5, 0.01f);
}

TEST(QuaternionTest, eulerAnglesYAxis)
{
	Quaternion q = Quaternion::EulerAngles(0, -120, 0);
	glm::vec3 euler = q.GetEulerAngles();
	EXPECT_NEAR(euler.x, 180, 0.001f);
	EXPECT_NEAR(euler.y, -60, 0.001f);
	EXPECT_NEAR(euler.z, 180, 0.001f);
}

TEST(QuaternionTest, eulerAnglesXZAxis)
{
	Quaternion q = Quaternion::EulerAngles(20, -80, 30);
	glm::vec3 euler = q.GetEulerAngles();
	EXPECT_NEAR(euler.x, 20, 0.001f);
	EXPECT_NEAR(euler.y, -80, 0.001f);
	EXPECT_NEAR(euler.z, 30, 0.001f);
}