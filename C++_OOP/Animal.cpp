#include "Animal.h"

Animal::Animal() : __age(0), __weight(0)
{
	__name = new char[20];
	strcpy_s(__name, 20, "Unknown");
}

Animal::Animal(const char* name, int age, double weight)
{
	__name = nullptr;
	setName(name);
	setAge(age);
	setWeight(weight);
}

Animal::Animal(const Animal& other) : __age(other.__age), __weight(other.__weight)
{
	__name = nullptr;
	copyString(__name, other.__name);
}

Animal::Animal(Animal&& other) noexcept : __name(other.__name), __age(other.__age), __weight(other.__weight)
{
	other.__name = nullptr;
	other.__age = 0;
	other.__weight = 0;
}

void Animal::setName(const char* name) { copyString(__name, name); }
void Animal::setAge(int age) { __age = age; }
void Animal::setWeight(double weight) { __weight = weight; }
char* Animal::getName() { return __name; }
int Animal::getAge() { return __age; }
double Animal::getWeight() { return __weight; }

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
	os << "Name: " << animal.__name << "\n";
	os << "Age: " << animal.__age << "\n";
	os << "Weight: " << animal.__weight << "\n";
	return os;
}