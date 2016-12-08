#ifndef __ARRAY_3D_HPP__
#define __ARRAY_3D_HPP__

template <class T>
class array3D
{
	public:
		array3D(int width, int height, int depth)
		{
			n_array = new T[width * height * depth];
		}

		~array3D()
		{
			if (n_array != 0) delete [] n_array;
			n_array = 0;
		}

		T& get(int x, int y, int z)
		{
			return n_array[(z * n_width) + (y * n_width) + x];
		}

		void resize(int width, int height, int depth)
		{
			T* new_arr = new T[width * height * depth];

			if (new_arr == 0) return;

			int t1, t2, t3, t4;

			int minx = (width < n_width ? width : n_width);
			int miny = (height < n_height ? height : n_height);
			int minz = (depth < n_depth ? depth : n_depth);

			for (int z = 0; z < minz; ++z)
			{
				t1 = z * width * height;
				t2 = z * n_width * n_height;

				for (int y = 0; y < miny; ++y)
				{
					t3 = y * width;
					t4 = y * width;

					for (int x = 0; x < minx; ++x)
					{
						new_arr[t1 + t3 + x] = n_array[t2 + t4 + x];
					}
				}
			}

			if (n_array != 0) delete [] n_array;

			n_array = new_arr;
			n_width = width;
			n_height = height;
			n_depth = depth;
		}

		int size() { return n_width * n_height * n_depth; }
		int width() { return n_width; }
		int height() { return n_height; }
		int depth() { return n_depth; }

	protected:
		T* n_array;

		int n_width;
		int n_height;
		int n_depth;
};

#endif // __ARRAY_3D_HPP__
