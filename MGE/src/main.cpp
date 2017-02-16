#include <Game\Application.hpp>
#include <gtest\gtest.h>

void LaunchGame()
{
	Application::Instance().Initialize();
	Application::Instance().Run();
}

int RunTests(int* argc, char** argv)
{
	testing::InitGoogleTest(argc, argv);
	return RUN_ALL_TESTS();
}

int main(int argc, char** argv) 
{
	//if (RunTests(&argc, argv) == 0)
	{
		LaunchGame();
	}
	/*else
	{
		std::getchar();
	}*/

	return 0;
}

