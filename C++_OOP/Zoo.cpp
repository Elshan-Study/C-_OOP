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
char* ZooWorker::getName() const { return _name; }
int ZooWorker::getExperience() const { return _experience; }

ZooWorker& ZooWorker::operator=(const ZooWorker& zooWorker)
{
    copyString(_name, zooWorker._name, 30);
    _experience = zooWorker._experience;

    return *this;
}

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

std::ostream& operator<<(std::ostream& os, const Enclosure& enclosure)
{
    os << "Enclosure Type: " << enclosure._type << "\n";
    os << "Caretaker: " << enclosure._caretaker.getName() << "\n";
    os << "Animals: " << "\n";
    for (int i = 0; i < enclosure._animalCount; i++)
    {
        os << i + 1 << "\n";
        os << *enclosure._animals[i] << "\n";
    }
    return os;
}

Enclosure& Enclosure::operator=(const Enclosure& enclosure)
{
    if (this == &enclosure)  
        return *this;

    delete[] _type;
    delete[] _animals;

    _type = nullptr;
    _animals = nullptr;

    copyString(_type, enclosure._type);
    copyAnimals(_animals, enclosure._animals, enclosure._animalCount);
    _capacity = enclosure._capacity;
    _animalCount = enclosure._animalCount;
    _caretaker = enclosure._caretaker;

    return *this;
}


Zoo::Zoo() : _enclosureCount(0), _capacity(5)
{
    _enclosures = new Enclosure[_capacity];
}

Zoo::Zoo(int capacity) : _enclosureCount(0), _capacity(capacity)
{
    _enclosures = new Enclosure[capacity];
}

Zoo::Zoo(const Zoo& other) : _enclosureCount(other._enclosureCount), _capacity(other._capacity)
{
    _enclosures = new Enclosure[other._capacity];
    for (size_t i = 0; i < other._enclosureCount; i++)
    {
        _enclosures[i] = other._enclosures[i];
    }
}

Zoo::Zoo(Zoo&& other) noexcept : _enclosureCount(other._enclosureCount), _enclosures(other._enclosures), _capacity(other._capacity)
{
    other._enclosures = nullptr;
    other._enclosureCount = 0;
    other._capacity = 0;
}

Zoo::~Zoo() {
    _enclosureCount = 0;
    _capacity = 0;
    delete[] _enclosures;
}

void Zoo::addEnclosure(const Enclosure& enclosure)
{
    if (_enclosureCount >= _capacity || !_enclosures) {
        return;
    }
    _enclosures[_enclosureCount++] = enclosure;
}

std::ostream& operator<<(std::ostream& os, const Zoo& zoo)
{
    os << "Zoo Info:\n";
    for (int i = 0; i < zoo._enclosureCount; i++)
    {
        os << zoo._enclosures[i] << "\n";
        os << "_____________________\n";
    }

    return os;
}