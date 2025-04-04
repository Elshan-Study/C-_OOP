#include <iostream>

/*early building*/
//class A
//{
//public:
//	void foo() {};
//};
//
//int main()
//{
//	A obj;
//	obj.foo(); 
//	return 0;
//}

/*late building*/
//class A
//{
//public:
//	virtual void foo() 
//	{
//		std::cout << "A::Foo\n";
//	};
//};
//
//class B : public A
//{
//public:
//	void foo() override 
//	{
//		std::cout << "B::Foo\n";
//	};
//};
//
//int main()
//{
//	A* obj = new B();
//	obj->foo(); 
//	return 0;
//}

class A
{

};

class B final : public A
{

};

//class C : public B «¿œ–≈Ÿ≈ÕŒ.  À¿—— ¬ »Ã≈≈“ ‘»Õ¿À
//{
//
//};