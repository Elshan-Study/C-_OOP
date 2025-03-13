#include "SuperVector.h"
#include <iostream>

SuperVector::SuperVector() : _data(nullptr), _size(0), _capacity(0){}
SuperVector::SuperVector(size_t size) : _size(size), _capacity(size)
{
	_data = new int[_capacity]();
}
SuperVector::SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity)
{
	_data = new int[_capacity];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

int SuperVector::Get(size_t index) const
{
	if (index < _size && index >= 0)
	{
		return _data[index];
	}

	return 0;
}

void SuperVector::PushBack(int value) {
	if (_size >= _capacity) {
		Resize(2);
	}
	_data[_size++] = value;
}

void SuperVector::Set(int value, size_t index) {
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

void SuperVector::Insert(int value, size_t index) {
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


void SuperVector::Pop() {
	if (_size > 0) {
		_size--;

		if (_size < _capacity / 4 && _capacity > 1) {
			Resize(0.5);
		}
	}
}

void SuperVector::Remove(size_t index) {
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

size_t SuperVector::Size() const
{
	return _size;
}

SuperVector::~SuperVector()
{
	delete[] _data;
}

/*homework 19*/
SuperVector SuperVector::operator+(const SuperVector& other) {
	size_t newSize = _size >= other._size ? _size : other._size;
	SuperVector newVector(newSize);

	for (size_t i = 0; i < newSize; i++) {
		int val1 = (i < _size) ? _data[i] : 0;
		int val2 = (i < other._size) ? other._data[i] : 0;
		newVector[i] = val1 + val2;
	}

	return newVector;
}

SuperVector SuperVector::operator-(const SuperVector& other) {
	size_t newSize = _size >= other._size ? _size : other._size;
	SuperVector newVector(newSize);

	for (size_t i = 0; i < newSize; i++) {
		int val1 = (i < _size) ? _data[i] : 0;
		int val2 = (i < other._size) ? other._data[i] : 0;
		newVector[i] = val1 - val2;
	}

	return newVector;
}

SuperVector SuperVector::operator*(const SuperVector& other) {
	size_t newSize = _size >= other._size ? _size : other._size;
	SuperVector newVector(newSize);

	for (size_t i = 0; i < newSize; i++) {
		int val1 = (i < _size) ? _data[i] : 0;
		int val2 = (i < other._size) ? other._data[i] : 0;
		newVector[i] = val1 * val2;
	}

	return newVector;
}

SuperVector SuperVector::operator/(const SuperVector& other) {
	size_t newSize = _size >= other._size ? _size : other._size;
	SuperVector newVector(newSize);

	for (size_t i = 0; i < newSize; i++) {
		int val1 = (i < _size) ? _data[i] : 0;
		int val2 = (i < other._size) ? other._data[i] : 0;
		if (val2 == 0)
		{
			newVector[i] = val1;
			continue;
		}

		newVector[i] = val1 / val2;
	}

	return newVector;
}

int& SuperVector::operator[](size_t index)
{
	return _data[index];
}

const int& SuperVector::operator[](size_t index) const
{
	return _data[index];
}

/*homework 20*/
void SuperVector::operator+=(const SuperVector& other)
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] += other._data[i];
	}
	return;
}

void SuperVector::operator+=(int value)
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] += value;
	}

	return;
}

void SuperVector::operator-=(const SuperVector& other)
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] -= other._data[i];
	}
	return;
}

void SuperVector::operator-=(int value)
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] -= value;
	}
	return;
}

void SuperVector::operator*=(const SuperVector& other)
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] *= other._data[i];
	}
	return;
}

void SuperVector::operator*=(int value)
{
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] *= value;
	}
	return;
}

void SuperVector::operator/=(const SuperVector& other)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (other._data[i] == 0)
		{
			return;
		}
		_data[i] /= other._data[i];
	}
	return;
}

void SuperVector::operator/=(int value)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (value == 0)
		{
			return;
		}
		_data[i] /= value;
	}
	return;
}

SuperVector& SuperVector::operator++()
{
	for (size_t i = 0; i < _size; i++)
	{
		++_data[i];
	}
	return *this;
}

SuperVector SuperVector::operator++(int)
{
	SuperVector temp = *this;
	++(*this); 
	return temp; 
}

SuperVector& SuperVector::operator--()
{
	for (size_t i = 0; i < _size; i++)
	{
		--_data[i];
	}
	return *this;
}

SuperVector SuperVector::operator--(int)
{
	SuperVector temp = *this; 
	--(*this); 
	return temp; 
}

std::ostream& operator<<(std::ostream& os, const SuperVector& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		os << vector[i] << " ";
	}
	os << "\n";
	return os;
}

std::istream& operator>>(std::istream& is, SuperVector& vector)
{

	for (size_t i = 0; i < vector.Size(); i++)
	{
		is >> vector[i];
	}

	return is;
}
