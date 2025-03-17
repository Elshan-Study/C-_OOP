#include "Zoo.h"

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
	_name = nullptr;
	copyString(_name, other._name);
}

ZooWorker::ZooWorker(ZooWorker&& other) noexcept : _experience(other._experience)
{
	other._name = nullptr;
	other._experience = 0;
}

ZooWorker::~ZooWorker() {
	delete[] _name;
	_experience = 0;
}

void ZooWorker::setName(const char* name) { copyString(_name, name); }
void ZooWorker::setExperience(int experience) { _experience = experience; }
char* ZooWorker::getName() { return _name; }
int ZooWorker::getExperience() { return _experience; }
