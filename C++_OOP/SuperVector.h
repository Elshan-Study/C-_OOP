#pragma once
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
	SuperVector();
	SuperVector(size_t size);
	SuperVector(const SuperVector& other);

	int Get(size_t index) const;
	void PushBack(int value);
	void Set(int value, size_t index);
	void Insert(int value, size_t index);
	void Pop();
	void Remove(size_t index);
	size_t Size() const;
	~SuperVector();

	/*homework 19*/
	SuperVector operator+(const SuperVector& other);
	SuperVector operator-(const SuperVector& other);
	SuperVector operator*(const SuperVector& other);
	SuperVector operator/(const SuperVector& other);
	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	/*homework 20*/
};