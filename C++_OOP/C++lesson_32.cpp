#include <iostream>
#include <stack>
#include <queue>

//LIFO - Last in First out (stack)
//FIFO - First in First out (queue)
//LIFO + FIFO - (Deque)
//a->b

void b();
void c();

void a()
{
	std::cout << "a" << "\n";
	b();
	std::cout << "a end" << "\n";
}

void b()
{
	std::cout << "b" << "\n";
	c();
	std::cout << "b end" << "\n";
	c();
}

void c()
{
	std::cout << "c" << "\n";
}

//int main()
//{
//	std::stack<int> values;
//	std::queue<int> queue;
//
//	values.push(10);
//	values.push(20);
//	values.push(30);
//
//	return 0;
//}