#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include "array.hpp"

template <class T>
class queue : public array<T>
{
	public:
		int n_front;
		int n_count;

		array* n_array;

		queue(int size) : array<T>(size)
		{
			n_front = 0;
			n_count = 0;
		}

		bool enqueue(T data)
		{
			if (n_size != n_count)
			{
				n_array[(n_count + n_front) % n_size] = data;
				++n_count;
				return true;
			}
		}

		void dequeue()
		{
			if (n_count > 0)
			{
				--n_count;
				++n_front;

				if (n_front == n_size) n_front = 0;
			}
		}

		T front() { return n_array[n_front]; }

		T& operator[](int index)
		{
			return n_array[(index + n_front) % n_size];
		}
};

#endif // __QUEUE_HPP__
