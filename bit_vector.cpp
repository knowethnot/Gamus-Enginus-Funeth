#include "bitvector.hpp"

#include <stdio.h>

BitVector::BitVector(int size) : n_array(0), n_size(0)
{
	Resize(size);
}

BitVector::~BitVector()
{
	if (n_array != 0) delete [] n_array;
	n_array = 0;
}

void BitVector::resize(int size)
{
	unsigned long int* new_vec = 0;

	if (size % 32 == 0) size = size / 32;
	else { size = (size / 32) + 1; }

	new_vec = new unsigned long int[size];

	if (new_vec == 0) return;

	int min;

	if (size < n_size) min = size;
	else { min = n_size; }

	for (int i = 0; i < min; ++i)
	{
		new_vec[i] = n_array[i];
	}

	n_size = size;

	if (n_array != 0) delete [] n_array;
	n_array = new_vec;
}

bool BitVector::operator[](int index)
{
	int cell = index / 32;
	int bit = index % 32;
	return (n_array[cell] & (1 << bit)) >> bit;
}

void BitVector::set(int index, bool value)
{
	int cell = index / 32;
	int bit = index % 32;

	if (value == true)
	{
		n_array[cell] = (n_array[cell] | (1 << bit));
	}

	else
	{
		n_array[cell] = (n_array[cell] & (~(1 << bit)));
	}
}

void BitVector::clear()
{
	for (int i = 0; i < n_size; ++i)
	{
		n_array[i] = 0;
	}
}

void BitVector::set_all()
{
	for (int i = 0; i < n_size; ++i)
	{
		n_array[i] = 0xFFFFFFFF;
	}
}

bool BitVector::write(const char* filename)
{
	FILE* output = 0;
	int write = 0;
	
	output = fopen(filename, "wb");
	if (output == 0) return false;

	write = fwrite(n_array, sizeof(unsigned long int), n_size, output);

	fclose(output);
	if (write != n_size) return false;

	return true;
}

bool BitVector::read(const char* filename)
{
	FILE* input = 0;
	int read = 0;

	input = fopen(filename, "rb");
	if (input == 0) return false;

	read = fread(n_array, sizeof(unsigned long int), n_size, input);

	fclose(input);
	if (read != n_size) return false;

	return true;
}
