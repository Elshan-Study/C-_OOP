#pragma once
#include <string.h>
#include <iostream>
class Animal
{
protected:
	char* __name;
	int __age;
	double __weight;

	void copyString(char*& dest, const char* src)
	{
		delete[] dest;
		if (src)
		{
			dest = new char[strlen(src) + 1];
			strcpy_s(dest, strlen(src) + 1, src);
		}
		else
		{
			dest = new char[20];
			strcpy_s(dest, 20, "Unknown");
		}
	}
public:
	Animal();

	explicit Animal(const char* name, int age, double weight);

	Animal(const Animal& other);

	Animal(Animal&& other) noexcept;

	void setName(const char* name);
	void setAge(int age);
	void setWeight(double weight);
	char* getName();
	int getAge();
	double getWeight();

	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
};

