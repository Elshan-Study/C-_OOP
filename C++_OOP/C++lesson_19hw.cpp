#include <iostream>
#include "SuperVector.h"

void DisplayVector(const SuperVector& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector.Get(i) << " ";
	}
};

//int main()
//{
//	SuperVector v(3);
//	SuperVector v2(3);
//	v[0] = 1;
//	v[1] = 3;
//	v[2] = 5;
//	v2[0] = 2;
//	v2[1] = 4;
//	v2[2] = 0;
//	SuperVector v3(v/v2);
//
//	DisplayVector(v3);
//	std::cout << std::endl;
//
//	return 0;
//}