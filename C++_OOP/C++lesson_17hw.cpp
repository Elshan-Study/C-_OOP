#include <iostream>

class SuperVector
{
private:
	int* _data;
	size_t _size;
	size_t _capacity;

	void Resize(float factor)
	{
		size_t newCapacity = _capacity == 0 ? 1 : _capacity * factor;
		int* SuperVectorTemp = new int[newCapacity];
		for (size_t i = 0; i < _size; i++) 
		{
			SuperVectorTemp[i] = _data[i];
		}
		delete[] _data;
		_data = SuperVectorTemp;
		_capacity = newCapacity;
	}

public:
	SuperVector() : _data(nullptr), _size(0), _capacity(0){}
	SuperVector(size_t size) : _size(size), _capacity(size)
	{
		_data = new int[_capacity]();
	}
	SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity)
	{
		_data = new int[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
	}

	int Get(size_t index) const
	{
		if (index < _size && index >= 0)
		{
			return _data[index];
		}

		return 0;
	}

	void PushBack(int value) {
		if (_size >= _capacity) {
			Resize(2);
		}
		_data[_size++] = value;
	}

	void Set(int value, size_t index) { 
		if (index >= _size)
		{
			return;
		}
		
		if (index < _size) {
			_data[index] = value;
			return;
		}

		while (_capacity <= index) {
			_capacity = (_capacity == 0) ? 1 : _capacity * 2;
		}

		Resize(1); 

		for (size_t i = _size; i < index; i++) {
			_data[i] = 0;
		}

		_data[index] = value;
		_size = index + 1;
	}

	void Insert(int value, size_t index) {
		if (index >= _size) {
			return;
		}

		if (_size >= _capacity) {
			Resize(2);
		}

		for (size_t i = _size; i > index; --i) {
			_data[i] = _data[i - 1];
		}

		_data[index] = value;
		_size++;
	}


	void Pop() {
		if (_size > 0) {
			_size--;

			if (_size < _capacity / 4 && _capacity > 1) {
				Resize(0.5);
			}
		}
	}

	void Remove(size_t index) {
		if (index >= _size) {
			return;
		}

		for (size_t i = index; i < _size - 1; i++) {
			_data[i] = _data[i + 1];
		}

		_size--;

		if (_size < _capacity / 4 && _capacity > 1) {
			Resize(0.5);
		}
	}

	size_t Size() const
	{
		return _size;
	}

	~SuperVector()
	{
		delete[] _data;
	}
};

void DisplayVector(const SuperVector& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector.Get(i) << " ";
	}
}

int main()
{
	// Проверим работу Set() и PushBack()
	SuperVector v(10);
	v.PushBack(10);
	v.PushBack(20);
	v.Set(30, 5);
	v.Set(40, 1);
	v.Set(50, 10);

	DisplayVector(v);
	std::cout << std::endl;

	v.Pop();
	v.Remove(5);
	DisplayVector(v);
	std::cout << std::endl;

	v.Insert(20, 3);
	DisplayVector(v);
	std::cout << std::endl;

	return 0;
}