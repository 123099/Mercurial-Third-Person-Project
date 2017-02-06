#include "AudioListener.hpp"
#include <SFML\Audio\Listener.hpp>
#include <Core\GameObject.hpp>
#include <Behaviours\Transform.hpp>
#include <iostream>

int AudioListener::s_listenerCount = 0;

void AudioListener::SetGlobalVolume(float normalizedVolume)
{
	sf::Listener::setGlobalVolume(normalizedVolume * 100.0f);
}

void AudioListener::Awake()
{
	++s_listenerCount;

	if (s_listenerCount > 1)
	{
		std::cerr << "[Warning!] There are " << s_listenerCount << " audio listeners in the scene! Only 1 listener is allowed, otherweise, the results are unpredictable." << '\n';
	}
}

void AudioListener::Update()
{
	//Retrieve the world position
	const glm::vec3 worldPosition = m_gameObject->GetTransform()->GetWorldPosition();

	//Calculate a world orientation
	const glm::vec3 worldOrientation = m_gameObject->GetTransform()->GetWorldRotation() * glm::vec3(0, 0, -1);

	//Apply position and orientation
	sf::Listener::setPosition(worldPosition.x, worldPosition.y, worldPosition.z);
	sf::Listener::setDirection(worldOrientation.x, worldOrientation.y, worldOrientation.z);
}
