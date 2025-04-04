#include <iostream>
#define PI 3,14159265

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

//class A
//{
//
//};
//
//class B final : public A
//{
//
//};

//class C : public B ÇÀÏĞÅÙÅÍÎ. ÊËÀÑÑ Â ÈÌÅÅÒ ÔÈÍÀË
//{
//
//};


//class A
//{
//public:
//	virtual void Biba() {};
//};
//
//class B : public A
//{
//public:
//	void Biba() override final {};
//};
//
//class C : public B
//{
//public:
//	/*void Biba() override {}; final çàïğåòèë ïåğåîïğåäåëåíèå*/
//};

class Shape
{
public:
	virtual double area() const		= 0; /*pure virtual method*/
	virtual double perimetr() const = 0; /*pure virtual method*/

	virtual ~Shape() = default;
};

class Rectangle : public Shape
{
private:
	double _width;
	double _height;

public:
	Rectangle() : _width(0), _height(0) {};
	Rectangle(double width, double height) : _width(width), _height(height) {};

	double area() const override
	{
		return _width * _height;
	};

	double perimetr() const
	{
		return 2 * (_width + _height);
	}
};

class Circle : public Shape
{
private:
	double _radius;

public:
	Circle() : _radius(0) {};
	Circle(double radius) : _radius(radius) {};

	double area() const override
	{
		return PI * (_radius * _radius);
	};

	double perimetr() const
	{
		return 2 * PI * _radius;
	}
};

int main()
{
	/*Shape shape; prohibited by virtual method*/

	Rectangle rec(4.0, 6.0);
	Circle circle(5.0);

	Shape* shapes[] = { &circle, &rec };

	for (Shape* shape : shapes)
	{
		std::cout << "Area: " << shape->area() << std::endl;
		std::cout << "Perimetr: " << shape->perimetr() << std::endl;
	}

	return 0;
}