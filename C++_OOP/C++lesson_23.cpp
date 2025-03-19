#include <iostream>
#include <memory>

//unique_ptr


class Biba
{
public:
	Biba() { std::cout << "Biba" << std::endl; }
	~Biba() { std::cout << "~Biba" << std::endl; }

	void sayHello()
	{
		std::cout << "Hello\n";
	}
};

//int main()
//{
//	std::unique_ptr<Biba> biba_ptr = std::make_unique<Biba>();
//	biba_ptr->sayHello();
//
//	std::unique_ptr<Biba> biba_ptr2 = std::move(biba_ptr);
//
//	std::unique_ptr<int[]> boba_ptr = std::make_unique<int[]>(5);
//
//	return 0;
//}