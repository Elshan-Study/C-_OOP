#include <iostream>
#include "SuperVector.h"
#include "SuperVectorT.h"
#include "Animal.h"
#include "Zoo.h"

void DisplayVector(const SuperVector& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
	{
		std::cout << vector.Get(i) << " ";
	}
};

//int main()
//{
//	/*homework 19*/
//
//	/*SuperVector v(3);
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
//	std::cout << std::endl;*/
//
//	/*homework 20*/
//	//SuperVector v1(3);
//	//SuperVector v2(4);
//
//	//std::cout << "Vector 1: \n";
//	//std::cin >> v1; 
//	//std::cout << v1;
//	///*std::cout << "Vector 2: \n";
//	//std::cin >> v2;
//	//std::cout << v2;*/
//	//std::cout << v1--;
//	//std::cout << v1;
//
//	/*homework 21*/
//	//ZooWorker caretaker("John Doe", 5);
//	//Enclosure enclosure("Savannah", 3, caretaker);
//	//Mammal* animal_1 = new Mammal("Lion", 5, 150.0, 1);
//	//Mammal* animal_2 = new Mammal("Elephant", 10, 500.0, 0);
//	//Reptile* animal_3 = new Reptile("Crocodile", 10, 100.0, 0);
//	//enclosure.addAnimal(animal_1);
//	//enclosure.addAnimal(animal_2);
//	//enclosure.addAnimal(animal_3);
//
//	////std::cout << enclosure;
//	///*enclosure.printEnclosureInfo();
//
//	//enclosure.removeAnimal(0);
//	//enclosure.printEnclosureInfo();*/
//
//	//Zoo zoo;
//	//zoo.addEnclosure(enclosure);
//	//std::cout << zoo;
//
//	/*homework 22*/
//
//	/*SuperVectorT <double> vectorT({ 11, 66, 55 });
//	SuperVectorT <double> vectorT2({ 5, 6.8, 45 });
//
//	SuperVectorT <double> vectorT3 = vectorT + vectorT2;
//	std::cout << vectorT3[5] << "\n";
//
//	vectorT += vectorT3;
//
//	std::cout << vectorT.Size();*/
//
//	return 0;
//}