#include "input.hpp"

void InputHandler::ProcEvents(SDL_Event event)
{
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
			{
				keyDown();
			} break;
			case SDL_KEYUP:
			{
				keyUp();
			} break;
			case SDL_QUIT:
			{
				exit(-1);
			} break;
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) const
{
	if (n_keystates != 0)
	{
		n_keystates[key] = 1;
		return true;
	}
	else { return false; }

	return false;
}

void InputHandler::keyDown()
{
	n_keystates = (std::uint_fast8_t*)SDL_GetKeyboardState(0);
}

void InputHandler::keyUp()
{
	n_keystates = (std::uint_fast8_t*)SDL_GetKeyboardState(0);
}
