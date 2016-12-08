#include "window.hpp"

int main()
{
	Window window;
	bool _terminate = false;

	window.Init("???", 640, 480);

	while (_terminate != true)
	{
		int p_time = SDL_GetTicks();
		window.P_Thread();
	}

	window.Clean();

	return 0;
}
