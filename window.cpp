#include "window.hpp"

bool Window::Init(const std::string &name, int width, int height)
{
	win_pos_x = SDL_WINDOWPOS_CENTERED;
	win_pos_y = SDL_WINDOWPOS_CENTERED;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		_window = SDL_CreateWindow(name.c_str(),
								   win_pos_x,
								   win_pos_y,
								   width,
								   height,
								   SDL_WINDOW_SHOWN);
	
		if (_window == NULL)
		{
			SDL_GetError();
			exit(-1);
		}
		else
		{
			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

			if (_renderer == NULL) 
			{
				SDL_GetError();
				exit(-1);
			}
			else { SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); }
		}
	}

	_quit = false;

	return true;
}

void Window::ProcEvents()
{
	while (_quit != true)
	{
		if (SDL_PollEvent(&_event))
		{
			switch (_event.type)
			{
				case SDL_QUIT:
				{
					exit(-1);
				} break;
			}
		}
	}
}

void Window::Render()
{
	SDL_RenderClear(_renderer);
	SDL_RenderPresent(_renderer);
}

void Window::Update()
{
	ProcEvents();
}

void Window::P_Thread()
{
	Update();
	Render();
}

void Window::Clean() const
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
