#include "Animal.h"

Animal::Animal() : _age(0), _weight(0)
{
	_name = new char[20];
	strcpy_s(_name, 20, "Unknown");
}

Animal::Animal(const char* name, int age, double weight)
{
	_name = nullptr;
	setName(name);
	setAge(age);
	setWeight(weight);
}

Animal::Animal(const Animal& other) : _age(other._age), _weight(other._weight)
{
	_name = nullptr;
	copyString(_name, other._name);
}

Animal::Animal(Animal&& other) noexcept : _name(other._name), _age(other._age), _weight(other._weight)
{
	other._name = nullptr;
	other._age = 0;
	other._weight = 0;
}

Animal::~Animal(){
	delete[] _name;
	_age = 0;
	_weight = 0;
}

void Animal::setName(const char* name) { copyString(_name, name); }
void Animal::setAge(int age) { _age = age; }
void Animal::setWeight(double weight) { _weight = weight; }
char* Animal::getName() { return _name; }
int Animal::getAge() { return _age; }
double Animal::getWeight() { return _weight; }

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
	os << "Name: " << animal._name << "\n";
	os << "Age: " << animal._age << "\n";
	os << "Weight: " << animal._weight << "\n";
	return os;
}

Mammal::Mammal() : _hasFur(0) {};
Mammal::Mammal(const char* name, int age, double weight, bool hasFur) : Animal(name, age, weight) { setFur(hasFur); };
Mammal::Mammal(const Mammal& other) : Animal(other), _hasFur(other._hasFur) {};
Mammal::Mammal(Mammal&& other) noexcept : Animal(std::move(other)), _hasFur(other._hasFur) {
	other._hasFur = 0;
}
Mammal::~Mammal() { _hasFur = 0; }

void Mammal::setFur(bool hasFur) { _hasFur = hasFur; }
bool Mammal::getFur() { return _hasFur; }

Bird::Bird() : _wingSpan(0) {};
Bird::Bird(const char* name, int age, double weight, double wingSpan) : Animal(name, age, weight) { setWingSpan(wingSpan); };
Bird::Bird(const Bird& other) : Animal(other), _wingSpan(other._wingSpan) {};
Bird::Bird(Bird&& other) noexcept : Animal(std::move(other)), _wingSpan(other._wingSpan) {
	other._wingSpan = 0;
}
Bird::~Bird() { _wingSpan = 0; }

void Bird::setWingSpan(double wingSpan) { _wingSpan = wingSpan; }
bool Bird::getWingSpan() { return _wingSpan; }

Reptile::Reptile() : _isVenomous(0) {};
Reptile::Reptile(const char* name, int age, double weight, bool isVenomous) : Animal(name, age, weight) { setVenomous(isVenomous); };
Reptile::Reptile(const Reptile& other) : Animal(other), _isVenomous(other._isVenomous) {};
Reptile::Reptile(Reptile&& other) noexcept : Animal(std::move(other)), _isVenomous(other._isVenomous) {
	other._isVenomous = 0;
}
Reptile::~Reptile() { _isVenomous = 0; }

void Reptile::setVenomous(bool isVenomous) { _isVenomous = isVenomous; }
bool Reptile::getVenomous() { return _isVenomous; }