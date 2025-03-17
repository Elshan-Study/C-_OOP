#include <iostream>
#include "SuperVector.h"
#include "Animal.h"

void DisplayVector(const SuperVector& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector.Get(i) << " ";
	}
};

int main()
{
	/*homework 19*/

	/*SuperVector v(3);
	SuperVector v2(3);
	v[0] = 1;
	v[1] = 3;
	v[2] = 5;
	v2[0] = 2;
	v2[1] = 4;
	v2[2] = 0;
	SuperVector v3(v/v2);

	DisplayVector(v3);
	std::cout << std::endl;*/


	//SuperVector v1(3);
	//SuperVector v2(4);

	//std::cout << "Vector 1: \n";
	//std::cin >> v1; 
	//std::cout << v1;
	///*std::cout << "Vector 2: \n";
	//std::cin >> v2;
	//std::cout << v2;*/
	//std::cout << v1--;
	//std::cout << v1;

	Mammal mammal("Lion", 23, 30, 1);
	Bird bird("Sparrow", 3, 0.3, 23);
	Reptile reptile("Crocodile", 32, 22, 0);

	std::cout << mammal;
	std::cout << bird;
	std::cout << reptile;


	return 0;
}