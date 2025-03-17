#include "Zoo.h"

void ZooWorker::copyString(char*& dest, const char* src, int size)
{
    delete[] dest;
    if (src)
    {
        dest = new char[strlen(src) + 1];
        strcpy_s(dest, strlen(src) + 1, src);
    }
    else
    {
        dest = new char[size];
        strcpy_s(dest, size, "Unknown");
    }
};

ZooWorker::ZooWorker() : _experience(0)
{
	_name = new char[30];
	strcpy_s(_name, 30, "Unknown");
}

ZooWorker::ZooWorker(const char* name, int experience)
{
	_name = nullptr;
	setName(name);
	setExperience(experience);
}

ZooWorker::ZooWorker(const ZooWorker& other) : _experience(other._experience)
{
	copyString(_name, other._name, 30);
}

ZooWorker::ZooWorker(ZooWorker&& other) noexcept : _experience(other._experience)
{
    copyString(_name, other._name, 30);
	other._name = nullptr;
	other._experience = 0;

}

ZooWorker::~ZooWorker() {
	delete[] _name;
	_experience = 0;
}

void ZooWorker::setName(const char* name) { copyString(_name, name, 30); }
void ZooWorker::setExperience(int experience) { _experience = experience; }
char* ZooWorker::getName() { return _name; }
int ZooWorker::getExperience() { return _experience; }

void Enclosure::copyString(char*& dest, const char* src)
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

void Enclosure::copyAnimals(Animal**& dest, Animal** src, int count)
{
    dest = new Animal * [count];
    for (int i = 0; i < count; ++i)
    {
        dest[i] = src[i];
    }
}

Enclosure::Enclosure() : _capacity(0), _animalCount(0), _type(nullptr), _animals(nullptr)
{
    copyString(_type, "Unknown");
}

Enclosure::Enclosure(const char* type, int capacity, const ZooWorker& caretaker)
    : _capacity(capacity), _animalCount(0), _caretaker(caretaker), _type(nullptr)
{
    copyString(_type, type);
    _animals = new Animal * [_capacity]();
}

Enclosure::Enclosure(const Enclosure& other)
    : _capacity(other._capacity), _animalCount(other._animalCount), _caretaker(other._caretaker), _type(nullptr)
{
    copyString(_type, other._type);
    copyAnimals(_animals, other._animals, other._animalCount);
}

Enclosure::Enclosure(Enclosure&& other) noexcept
    : _type(other._type), _capacity(other._capacity), _animals(other._animals), _animalCount(other._animalCount), _caretaker(std::move(other._caretaker))
{
    other._type = nullptr;
    other._animals = nullptr;
    other._capacity = 0;
    other._animalCount = 0;
}

Enclosure::~Enclosure()
{
    delete[] _type;
    for (int i = 0; i < _animalCount; ++i) {
        delete _animals[i];
    }
    delete[] _animals;
}

void Enclosure::setType(const char* type)
{
    copyString(_type, type);
}

void Enclosure::addAnimal(Animal* animal)
{
    if (!animal || _animalCount >= _capacity || !_animals) {
        return;
    }
    _animals[_animalCount++] = animal;
}

void Enclosure::removeAnimal(int index)
{
    if (index < 0 || index >= _animalCount || !_animals) {
        return;
    }
    delete _animals[index];
    for (int i = index; i < _animalCount - 1; i++) {
        _animals[i] = _animals[i + 1];
    }
    _animals[_animalCount - 1] = nullptr;
    _animalCount--;
}

void Enclosure::printEnclosureInfo()
{
    std::cout << "Enclosure Type: " << _type << "\n";
    std::cout << "Caretaker: " << _caretaker.getName() << "\n";
    std::cout << "Animals: " << "\n";
    for (int i = 0; i < _animalCount; i++)
    {
        std::cout << i + 1 << "\n";
        std::cout << *_animals[i] << "\n";
    }
}