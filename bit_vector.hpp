#ifndef __BIT_VECTOR_HPP__
#define __BIT_VECTOR_HPP__

class BitVector
{
	public:
		BitVector(int size);
		~BitVector();

		void resize(int size);

		bool operator[](int index);

		void set(int index, bool value);
		void clear();
		void set_all();

		bool write(const char* filename);
		bool read(const char* filename);

		int size() { return n_size; }

	protected:
		unsigned long int* n_array;
		int n_size;
};

#endif // __BIT_VECTOR_HPP__
