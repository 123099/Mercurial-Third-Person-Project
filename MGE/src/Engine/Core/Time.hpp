#pragma once
class Time 
{
public:
	Time() = delete;
	static float s_deltaTime; //Time to complete the last frame
	
	static float s_fixedDeltaTime; //Time per physics update
	static float s_maxTimeStep; //Max time per physics update

	static float s_frameRate; //FPS
	static long s_frameCount;

	static float s_gameTime; //Time at the beginning of the frame. This is the total time since the start of the game
};