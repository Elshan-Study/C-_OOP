#include <iostream>
#include <memory>

//unique_ptr
//shared_ptr

class Biba
{
public:
	int test = 5;
	Biba() { std::cout << "Biba" << std::endl; }
	~Biba() { std::cout << "~Biba" << std::endl; }

	void sayHello()
	{
		std::cout << "Hello\n";
	}
};

int main()
{
	std::unique_ptr<Biba> biba_ptr = std::make_unique<Biba>();
	biba_ptr->sayHello();

	std::unique_ptr<Biba> biba_ptr2 = std::move(biba_ptr);

	std::unique_ptr<int[]> boba_ptr = std::make_unique<int[]>(5);

	std::shared_ptr<Biba> biba_shared_ptr = std::make_shared<Biba>();
	std::shared_ptr<Biba> biba_shared_ptr2 = biba_shared_ptr;
	std::shared_ptr<Biba> biba_shared_ptr3 = biba_shared_ptr2;
	std::shared_ptr<Biba> biba_shared_ptr4 = biba_shared_ptr3;

	biba_shared_ptr2->test = 2;
	std::cout << biba_shared_ptr4->test;

	return 0;
}