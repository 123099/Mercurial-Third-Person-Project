#pragma once
#include <Behaviours\AbstractBehaviour.hpp>
#include <Behaviours\BehaviourAttributes.hpp>
#include <Behaviours\MeshRenderer.hpp>

class Terrain final : public AbstractBehaviour, public RequireBehaviours<MeshRenderer>
{
public:
	Terrain();

	void Awake() override final;

	void RecalculateMesh();

	int GetHeight();
	int GetWidth();
	int GetDepth();

	void SetHeight(int height);
	void SetWidth(int width);
	void SetDepth(int depth);
	void SetSize(int width, int depth);
private:
	int m_width;
	int m_depth;
	int m_height;

	MeshRenderer* m_meshRenderer;
};

