#include <iostream>

class SuperVector
{
private:
	int* _data;
	size_t _size;
	size_t _capacity;
public:
	SuperVector() : _data(nullptr), _size(0), _capacity(0){}
	SuperVector(size_t size) : _size(size), _capacity(size)
	{
		_data = new int[_capacity]();
	}
	SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity) /*copying constructor*/
	{
		_data = new int[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
	}
};

int main()
{
	SuperVector vector(10);
	SuperVector vector2(vector);

	return 0;
}