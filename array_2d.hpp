#ifndef __ARRAY_2D_HPP__
#define __ARRAY_2D_HPP__

template <class T>
class array2D
{
	public:
		array2D(int width, int height)
		{
			n_array = new T[width * height];
			n_width = width;
			n_height = height;
		}

		~array2D()
		{
			if (n_array != 0) delete [] n_array;
			n_array = 0;
		}

		T& get(int x, int y) { return n_array[y * n_width + x]; }

		void resize(int width, int height)
		{
			T* new_arr = new T[width * height];

			if (new_arr == 0) return;

			int x, y, t1, t2;

			int minx = (width < n_width ? width : n_width);
			int miny = (height < n_height ? height : n_height);

			for (y = 0; y < miny; ++y)
			{
				t1 = y * width;
				t2 = y * n_width;

				for (x = 0; x < minx; ++x)
				{
					new_arr[t1 + x] = n_array[t2 + x];
				}
			}

			if (n_array != 0) delete [] n_array;

			n_array = new_arr;
			n_width = width;
			n_height = height;
		}

		int width() { return n_width; }
		int height() { return n_height; }
		int size() { return n_width * n_height; }

	protected:
		T* n_array;
		int n_width;
		int n_height;
};

#endif // __ARRAY_2D_HPP__
