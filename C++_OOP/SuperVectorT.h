#pragma once
#include <iostream>

template<typename T>
class SuperVectorT
{

private:
	T* _data;
	size_t _size;
	size_t _capacity;

	void Resize(float factor)
	{
		size_t newCapacity = _capacity == 0 ? 1 : _capacity * factor;
		T* SuperVectorTemp = new T[newCapacity];
		for (size_t i = 0; i < _size; i++)
		{
			SuperVectorTemp[i] = _data[i];
		}
		delete[] _data;
		_data = SuperVectorTemp;
		_capacity = newCapacity;
	}

public:
	SuperVectorT() : _data(nullptr), _size(0), _capacity(0) {};
	explicit SuperVectorT(std::initializer_list<T> init_list) : _size(init_list.size()), _capacity(init_list.size())
	{
		_data = new T[_capacity];
		size_t index = 0;

		for (auto value : init_list)
		{
			_data[index++] = value;
		}
	};
	explicit SuperVectorT(size_t size) : _size(size), _capacity(size)
	{
		_data = new T[_capacity]();
	}
	SuperVectorT(const SuperVectorT& other) : _size(other._size), _capacity(other._capacity)
	{
		T* temp = new T[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = other._data[i];
		}

		delete[] _data;
		_data = temp;
	};

	T Get(size_t index) const
	{
		if (index < _size && index >= 0)
		{
			return _data[index];
		}

		return T();
	}

	void PushBack(T value) {
		if (_size >= _capacity) {
			Resize(2);
		}
		_data[_size++] = value;
	}

	void Set(T value, size_t index) {
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

	void Insert(T value, size_t index) {
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

	size_t Size()  const
	{
		return _size;
	}

	~SuperVectorT() {
		delete[] _data;
		_size = 0;
		_capacity = 0;
	}

	SuperVectorT operator+(const SuperVectorT& other) {
		size_t newSize = _size + other._size;
		SuperVectorT newVector(newSize);

		for (size_t i = 0; i < _size; i++) {
			newVector[i] = _data[i];
		}

		for (size_t i = _size; i < newSize; i++) {
			for (size_t j = 0; j < other._size; j++)
			{
				newVector[i] = other._data[j];
			}
		}
		return newVector;
	}

	T& operator[](size_t index) {
		if (index >= Size())
		{
			return _data[0];
		}
		return _data[index];
	}

	const T operator[](size_t index) const
	{
		if (index >= Size())
		{
			return _data[0];
		}
		return _data[index];
	}

	SuperVectorT& operator=(const SuperVectorT& vector)
	{
		_size = vector._size;
		_capacity = vector._capacity;
		
		T* temp = new T[_capacity];
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = vector._data[i];
		}

		delete[] _data;
		_data = temp;
		return *this;
	}

	void operator+=(const SuperVectorT& other)
	{
		size_t newSize = _size + other._size;
		SuperVectorT tempVector(newSize);

		for (size_t i = 0; i < _size; i++) {
			tempVector[i] = _data[i];
		}

		for (size_t i = _size; i < newSize; i++) {
			for (size_t j = 0; j < other._size; j++)
			{
				tempVector[i] = other._data[j];
			}
		}

		*this = tempVector;

		return;
	}

};

