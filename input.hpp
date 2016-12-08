#ifndef __INPUT_HANDLER_HPP__
#define __INPUT_HANDLER_HPP__

#include <SDL2/SDL.h>
#include <cstdint>

class InputHandler
{
	public:
		void ProcEvents(SDL_Event event);
		bool isKeyDown(SDL_Scancode key) const;
		void keyUp();
		void keyDown();

	private:
		std::uint8_t *n_keystates;
};

#endif // __INPUT_HANDLER_HPP__
