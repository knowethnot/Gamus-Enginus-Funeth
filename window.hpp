#ifndef __WINDOW_HPP__
#define	__WINDOW_HPP__

#include <string>
#include <SDL2/SDL.h>

class Window
{
	public:
		Window() 
			: _window(nullptr),
			  _renderer(nullptr)
		{ }

		bool Init(const std::string &name, int width, int height);

		void ProcEvents();
		void Render();
		void Update();

		void P_Thread();

		void Clean() const;

	private:
		SDL_Window*	  _window;
		SDL_Renderer* _renderer;
		SDL_Event	  _event;

		int32_t win_pos_x;
		int32_t win_pos_y;

		Rectangle _rectangle;
		
		bool _quit;
};

#endif // __WINDOW_HPP__
