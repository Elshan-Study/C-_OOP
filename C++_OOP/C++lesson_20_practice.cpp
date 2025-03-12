#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction fr_1(1, 2);
	Fraction fr_2 = fr_1;
	Fraction fr_3(3, 2);
	std::cout << fr_2 << std::endl;
	std::cout << fr_1 - fr_3 << std::endl;
	std::cout << fr_1 * fr_3 << std::endl;
	std::cout << fr_1 / fr_3 << std::endl;
	std::cout << (fr_1 <= fr_3) << std::endl;
	std::cout << (double)fr_1 << std::endl;
	std::cout << (double)fr_3 << std::endl;


	return 0;
}
