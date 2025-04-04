//#include <iostream>
//
//class Biba
//{
//private:
//	int test;
//public:
//	Biba(int test)
//	{
//		this->test = test;
//	}
//};
//
//class SuperVector
//{
//private:
//	int* _data;
//	size_t _size;
//	size_t _capacity;
//public:
//	SuperVector() : _data(nullptr), _size(0), _capacity(0){}
//	SuperVector(size_t size) : _size(size), _capacity(size)
//	{
//		_data = new int[_capacity]();
//	}
//	SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity) /*copying constructor*/
//	{
//		_data = new int[_capacity];
//		for (size_t i = 0; i < _size; i++)
//		{
//			_data[i] = other._data[i];
//		}
//	}
//
//	int Get(size_t index) const
//	{
//		if (index <= _size && index >= 0)
//		{
//			return _data[index];
//		}
//
//		return 0;
//	}
//
//	size_t Size() const
//	{
//		return _size;
//	}
//
//	~SuperVector()
//	{
//		delete[] _data;
//	}
//};
//
//void DisplayVector(const SuperVector& vector)
//{
//	for (size_t i = 0; i < vector.Size(); i++)
//	{
//		std::cout << vector.Get(i) << " ";
//	}
//}

//int main()
//{
//	SuperVector vector(50);
//	SuperVector vector2(vector);
//	DisplayVector(vector2);
//
//	return 0;
//}