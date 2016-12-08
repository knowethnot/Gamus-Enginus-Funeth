#ifndef __TIMER_HPP__
#define __TIMER_HPP__

class Timer
{
	public:
		void Init();
		void Start();
		void Stop();
		void Pause();
		void Resume();

		U32 Ticks() { return starting_time - paused_time; }

		bool Engaged();
		bool Paused();

	private:
		typedef unsigned int U32;
		
		U32 starting_time;
		U32 paused_time;

		bool n_engaged;
		bool n_paused;
};

#endif // __TIMER_HPP__
