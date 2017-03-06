#include "PostProcessRenderer.hpp"
#include <Core\GameObject.hpp>
#include <Behaviours\PostProcessors\PostProcessor.hpp>

void PostProcessRenderer::Render(RenderTexture & sceneTexture)
{
	glDisable(GL_DEPTH_TEST);

	RenderTexture* sourceTexture = &sceneTexture;
	RenderTexture* destinationTexture = nullptr;

	std::vector<PostProcessor*> processors = GameObject::FindObjectsOfType<PostProcessor>();
	const size_t count = processors.size();
	for (size_t i = 0; i < count; ++i)
	{
		//Create a new destination texture
		//If we are on the last post process effect, then set the destination texture as the scene texture
		destinationTexture = i < count - 1 ? new RenderTexture(sourceTexture->GetWidth(), sourceTexture->GetHeight()) : &sceneTexture;

		//Process the source texture and output the results into the destination texture
		destinationTexture->Activate(false);
			processors[i]->ProcessTexture(*sourceTexture, sceneTexture);
		destinationTexture->Deactivate();

		//Delete the source texture as it is no longer necessary
		if (sourceTexture != &sceneTexture)
		{
			delete sourceTexture;
		}

		//Swap source and destination
		sourceTexture = destinationTexture;
	}

	glEnable(GL_DEPTH_TEST);
}
