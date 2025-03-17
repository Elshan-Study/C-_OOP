#pragma once
#include <string.h>
class Zoo
{
};


class ZooWorker
{
private:
	char* _name;
	int _experience;

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
			dest = new char[30];
			strcpy_s(dest, 30, "Unknown");
		}
	}
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

