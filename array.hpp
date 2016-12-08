#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <class T>
class array
{
	public:
		array(int size) : n_size(size)
		{
			n_array = new T[size];
		}

		~array()
		{
			delete [] n_array;
		}

		void resize(int size)
		{
			T*  new_arr = new T[size];

			if (new_arr == 0) return;

			int min;

			if (size < n_size) min = n_size;
			else { min = n_size; }

			for (int i = 0; i < min; ++i)
			{
				new_arr[i] = n_array[i];
			}

			n_size = size;

			if (n_array != 0) delete [] n_array;

			n_array = new_arr;
		}

		void insert(T item, int index)
		{
			for (int i = n_size - 1; i > index; --i)
			{
				n_array[i] = n_array[i - 1];
			}

			n_array[index] = item;
		}

		void remove(int index)
		{
			for (int i = index + 1; i < n_size; ++i)
			{
				n_array[i - 1] = n_array[i];
			}
		}

		bool write(const char* filename)
		{
			FILE* output = 0;
			int write = 0;

			output = fopen(filename, "wb");
			if (output == 0) return false;
			write = fwrite(n_array, sizeof(T), n_size, output);
			fclose(output);
			if (write != n_size) return false;

			return true;
		}
		
		bool read(const char* filename)
		{
			FILE* input = 0;
			int read = 0;

			input = fopen(filename, "rb");
			if (input == 0) return false;
			read = fread(n_size, sizeof(T), n_size, input);
			fclose(input);
			if (read != n_size) return false;

			return true;
		}

		T& operator[](int index) { return n_array[index]; }

		operator T*() { return n_array; }

		int size() { return n_size; }

	protected:
		T* n_array;
		int n_size;
};

#endif // __ARRAY_HPP__
