#include <iostream>
#include <string>

class file_exception : public std::exception
{
private:
	std::string _msg;
public:
	file_exception(std::string& msg) : _msg(msg) {}

	const char* what() const noexcept override
	{
		return _msg.c_str();
	}
	
};

int main()
{
	try 
	{
		int a = 5, b = 0;

		if (b == 0)
		{
			throw std::invalid_argument("Invalid input. Zero division error");
		}

		std::cout << a / b << "\n";
	}
	
	catch (std::exception &e)
	{
		std::cout << "Test\n";
		std::cout << e.what() << "\n";
	}

	return 0;
}