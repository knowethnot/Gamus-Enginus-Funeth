#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "array.hpp"

template <class T>
class stack : public array<T>
{
	public:
		int n_top;

		stack(int size) : array<T>(size)
		{
			n_top = 0;
		}

		bool push(T data)
		{
			if (n_size != n_top)
			{
				n_array[n_top] = data;
				++n_top;
				return true;
			}

			return false;
		}

		void pop()
		{
			if (n_top > 0) --n_top;
		}

		T top()
		{
			return n_array[n_top - 1;];
		}

		int count()
		{
			return n_top;
		}
};

#endif // __STACK_HPP__
