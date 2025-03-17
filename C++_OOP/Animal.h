#pragma once
#include <string.h>
#include <iostream>

class Animal
{
private:
	char* _name;
	int _age;
	double _weight;

	void copyString(char*& dest, const char* src, int size)
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
	}

public:
	Animal();

	explicit Animal(const char* name, int age, double weight);

	Animal(const Animal& other);

	Animal(Animal&& other) noexcept;
	~Animal();

	void setName(const char* name);
	void setAge(int age);
	void setWeight(double weight);
	char* getName() const;
	int getAge() const;
	double getWeight() const;

	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
};

class Mammal : public Animal
{
private:
	bool _hasFur;
public:
	Mammal();
	explicit Mammal(const char* name, int age, double weight, bool hasFur);
	Mammal(const Mammal& other);
	Mammal(Mammal&& other) noexcept;
	~Mammal();

	void setFur(bool hasFur);
	bool getFur() const;
};

class Bird : public Animal
{
private:
	double _wingSpan;
public:
	Bird();
	explicit Bird(const char* name, int age, double weight, double wingSpan);
	Bird(const Bird& other);
	Bird(Bird&& other) noexcept;
	~Bird();

	void setWingSpan(double wingSpan);
	bool getWingSpan() const;
};

class Reptile : public Animal
{
private:
	bool _isVenomous;
public:
	Reptile();
	explicit Reptile(const char* name, int age, double weight, bool isVenomous);
	Reptile(const Reptile& other);
	Reptile(Reptile&& other) noexcept;
	~Reptile();

	void setVenomous(bool isVenomous);
	bool getVenomous() const;
};



