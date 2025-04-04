#include <iostream>

class A
{
public:
	virtual ~A() 
	{
		std::cout << "delete A \n";
	}
};

class B : A
{
public:
	~B() override
	{
		std::cout << "delete B \n";
	}
};

class Character
{
protected:
	std::string _name;
	int _hp;
	int _stamina;
public:
	Character() : _name(""), _hp(0), _stamina(0) {};
	Character(std::string name, int hp, int stamina) : _name(name), _hp(hp), _stamina(stamina) {};

	virtual void attack()
	{
		std::cout << "class Character \n";
		std::cout << _name << " attacks " << _hp << " HP" << std::endl;
	}

	virtual void defend()
	{
		std::cout << "class Character \n";
		std::cout << _name << " defends " << _hp << " HP" << std::endl;
	}
};

class Player : public Character
{
public:
	Player() {};
	Player(std::string name, int hp, int stamina) : Character(name, hp, stamina) {};

	void attack() override
	{
		std::cout << "class Player \n";
		std::cout << _name << " attack " << _hp << " HP" << std::endl;
	}

	void defend() override
	{
		std::cout << "class Player \n";
		std::cout << _name << " defend " << _hp << " HP" << std::endl;
	}
};

class Orc : public Character
{
public:
	Orc() {};
	Orc(std::string name, int hp, int stamina) : Character(name, hp, stamina) {};

	void attack() override
	{
		std::cout << "class Orc \n";
		std::cout << _name << " attack " << _hp << " HP" << std::endl;
	}

	void defend() override
	{
		std::cout << "class Orc \n";
		std::cout << _name << " defend " << _hp << " HP" << std::endl;
	}
};


//int main()
//{
//	/*Player player("Player1", 10, 20);
//	player.attack();*/
//
//	Character** character = new Character*[2];
//	character[0] = new Player("Player1", 10, 20);
//	character[1] = new Orc("Orc1", 50, 100);
//
//	character[0]->attack();
//
//	return 0;
//}
