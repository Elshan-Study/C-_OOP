#include <iostream>

namespace MsSql
{
	void connect(std::string connectionString)
	{
		std::cout << "Connected..." << "\n";
	};

	void disconnect()
	{
		std::cout << "Diconnected..." << "\n";
	};
}

void* socket() { return nullptr;}

//int main()
//{
//	void* socket = ::socket();
//
//	std::cout << socket << "\n";
//
//	MsSql::connect("127.0.0.1");
//	MsSql::disconnect();
//}
