#include "timer.hpp"

#include <SDL2/SDL.h>

void Timer::Init()
{
	starting_time = 0;
	paused_time = 0;
	n_engaged = false;
	n_paused = false;
}

void Timer::Start()
{
	n_engaged = true;
	n_paused = false;
	starting_time = SDL_GetTicks();
}

void Timer::Stop()
{
	n_engaged = false;
	n_paused = false;
	starting_time = 0;
	n_paused = 0;
}

void Timer::Pause()
{
	if (n_engaged && !n_paused)
	{
		n_paused = true;
		paused_time = SDL_GetTicks() - starting_time;
		starting_time = 0;
	}
}

void Timer::Resume()
{
	if (n_engaged && n_paused)
	{
		n_paused = false;
		starting_time = SDL_GetTicks() - paused_time;
		paused_time = 0;
	}
}

U32 Timer::Ticks()
{
	U32 current_time = 0;

	if (n_engaged)
	{
		if (n_paused)
		{
			current_time = paused_time;
		}
		else
		{
			current_time = SDL_GetTicks() - timstarting_time;
		}
	}

	return current_time;
}

bool Timer::Engaged()
{
	return n_engaged;
}

bool Timer::Paused()
{
	return n_paused;
}
