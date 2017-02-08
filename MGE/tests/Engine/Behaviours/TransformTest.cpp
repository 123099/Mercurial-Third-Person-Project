#include <gtest\gtest.h>
#include <Behaviours\Transform.hpp>
#include <GameObject.hpp>
#include <Managers\SceneManager.hpp>
#include <Utils\Quaternion.hpp>

TEST(TransformTest, setWorldPosition)
{
	Transform t;
	t.SetWorldPosition(glm::vec3(10, 7, 5));
	EXPECT_TRUE(glm::vec3(10, 7, 5) == t.GetLocalPosition());
}

TEST(TransformTest, setWorldRotation)
{
	Transform t;
	t.SetWorldRotation(glm::angleAxis(glm::radians(30.0f), glm::vec3(0, 1, 0)));
	EXPECT_NEAR(30.0f, t.GetEulerAngles().y, 0.001f);
}

TEST(TransformTest, setScale)
{
	Transform t;
	t.SetLocalScale(glm::vec3(5, 2, 0.5));
	EXPECT_TRUE(glm::vec3(5, 2, 0.5) == t.GetLocalScale());
}

TEST(TransformTest, rotateSelf)
{
	Transform t;
	t.Rotate(glm::vec3(0, 30, 30));
	glm::vec3 rot = t.GetLocalRotation().GetEulerAngles();
	EXPECT_NEAR(rot.x, 0.0f, 0.001f);
	EXPECT_NEAR(rot.y, 30.0f, 0.001f);
	EXPECT_NEAR(rot.z, 30.0f, 0.001f);
}
/*
TEST(TransformTest, addChildParent)
{
	SceneManager::Instance().SetActiveScene(SceneManager::Instance().CreateScene("Scene"));

	GameObject* parent = new GameObject("Parent");
	GameObject* child = new GameObject("Child");

	child->GetTransform()->SetParent(parent->GetTransform());

	EXPECT_EQ(parent->GetTransform()->GetChildCount(), 1);

	delete parent;
	parent = nullptr;
	child = nullptr;
	SceneManager::Instance().DestroyActiveScene();
}

TEST(TransformTest, rotateWorld)
{
	SceneManager::Instance().SetActiveScene(SceneManager::Instance().CreateScene("Scene"));

	GameObject* parent = new GameObject();
	GameObject* child = new GameObject();

	parent->GetTransform()->Rotate(glm::vec3(0, 50, 0));
	child->GetTransform()->SetParent(parent->GetTransform());

	child->GetTransform()->Rotate(glm::vec3(30, 30, 0), Space::World);

	glm::vec3 rot = child->GetTransform()->GetLocalRotation().GetEulerAngles();
	EXPECT_NEAR(rot.x, 30.0f, 0.001f);
	EXPECT_NEAR(rot.y, -20.0f, 0.001f);
	EXPECT_NEAR(rot.z, 0.0f, 0.001f);

	SceneManager::Instance().DestroyActiveScene();
}

TEST(TransformTest, getWorldPosition)
{
	SceneManager::Instance().SetActiveScene(SceneManager::Instance().CreateScene("Scene"));

	GameObject* parent = new GameObject();
	GameObject* child = new GameObject();

	parent->GetTransform()->SetLocalPosition(glm::vec3(50, 100, 200));
	child->GetTransform()->SetLocalPosition(glm::vec3(0, 50, 0));

	child->GetTransform()->SetParent(parent->GetTransform());

	glm::vec3 worldPos = child->GetTransform()->GetWorldPosition();
	EXPECT_NEAR(worldPos.x, 0.0f, 0.001f);
	EXPECT_NEAR(worldPos.y, 50.0f, 0.001f);
	EXPECT_NEAR(worldPos.z, 0.0f, 0.001f);

	SceneManager::Instance().DestroyActiveScene();
}

TEST(TransformTest, getLocalPosition)
{
	SceneManager::Instance().SetActiveScene(SceneManager::Instance().CreateScene("Scene"));

	GameObject* parent = new GameObject();
	GameObject* child = new GameObject();

	parent->GetTransform()->SetLocalPosition(glm::vec3(50, 100, 200));
	child->GetTransform()->SetLocalPosition(glm::vec3(0, 50, 0));

	child->GetTransform()->SetParent(parent->GetTransform());

	glm::vec3 localPos = child->GetTransform()->GetLocalPosition();
	EXPECT_NEAR(localPos.x, -50.0f, 0.001f);
	EXPECT_NEAR(localPos.y, -50.0f, 0.001f);
	EXPECT_NEAR(localPos.z, -200.0f, 0.001f);

	SceneManager::Instance().DestroyActiveScene();
}

TEST(TransformTest, getWorldRotation)
{
	SceneManager::Instance().SetActiveScene(SceneManager::Instance().CreateScene("Scene"));

	GameObject* parent = new GameObject();
	GameObject* child = new GameObject();

	parent->GetTransform()->Rotate(glm::vec3(30, 30, 0));
	child->GetTransform()->Rotate(glm::vec3(30, 0, 0));

	child->GetTransform()->SetParent(parent->GetTransform());

	Quaternion worldRotation = child->GetTransform()->GetWorldRotation();
	const glm::vec3 rot = worldRotation.GetEulerAngles();
	
	EXPECT_NEAR(rot.x, 30.0f, 0.001f);
	EXPECT_NEAR(rot.y, 0.0f, 0.001f);
	EXPECT_NEAR(rot.z, 0.0f, 0.001f);

	SceneManager::Instance().DestroyActiveScene();
}

TEST(TransformTest, getLocalRotation)
{
	SceneManager::Instance().SetActiveScene(SceneManager::Instance().CreateScene("Scene"));

	GameObject* parent = new GameObject();
	GameObject* child = new GameObject();

	parent->GetTransform()->Rotate(glm::vec3(0, 30, 0));
	child->GetTransform()->Rotate(glm::vec3(30, 0, 0));

	child->GetTransform()->SetParent(parent->GetTransform());

	Quaternion worldRotation = child->GetTransform()->GetLocalRotation();
	const glm::vec3 rot = worldRotation.GetEulerAngles();

	EXPECT_NEAR(rot.x, 30.0f, 0.01f);
	EXPECT_NEAR(rot.y, -30.0f, 0.01f);
	EXPECT_NEAR(rot.z, 0.0f, 0.01f);

	SceneManager::Instance().DestroyActiveScene();
}*/