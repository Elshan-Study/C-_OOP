#pragma once
#include <string.h>
#include "Animal.h"

class ZooWorker
{
private:
	char* _name;
	int _experience;

    void copyString(char*& dest, const char* src, int size);
public:
	ZooWorker();
	explicit ZooWorker(const char* name, int experience);
	ZooWorker(const ZooWorker& other);
	ZooWorker(ZooWorker&& other) noexcept;
	~ZooWorker();

	void setName(const char* name);
	void setExperience(int experience);
	char* getName();
	int getExperience();
};

class Enclosure
{
private:
    char* _type;
    int _capacity;
    Animal** _animals;
    int _animalCount;
    ZooWorker _caretaker;

    void copyString(char*& dest, const char* src);
    void copyAnimals(Animal**& dest, Animal** src, int count);

public:
    Enclosure();
    explicit Enclosure(const char* type, int capacity, const ZooWorker& caretaker);

    Enclosure(const Enclosure& other);

    Enclosure(Enclosure&& other) noexcept;

    ~Enclosure();

    void setType(const char* type);

    void addAnimal(Animal* animal);

	void removeAnimal(int index);


    void printEnclosureInfo();

};
