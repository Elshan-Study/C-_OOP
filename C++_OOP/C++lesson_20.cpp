#include <iostream>

class Biba
{
private:
	int test;
public:
	Biba() : test(0){}
	Biba(int test)
	{
		this->test = test;
	}

	const int get() const
	{
		return this->test;
	}

	friend void display_biba(const Biba& biba);
};

void display_biba(const Biba& biba)
{
	std::cout << "Test: " << biba.test << "\n";
}

class Point
{
private:
	double _x;
	double _y;

public:
	Point();
	Point(double x, double y);
	Point(const Point& other);

	Point operator+(const Point& other) const;

	Point operator-(const Point& other) const;

	Point& operator=(const Point& other);

	Point& operator=(Point&& other);

	double& operator[](size_t index);

	const double& operator[](size_t index) const;

	Point& operator++(); /*++point*/
	Point operator++(int); /*point++*/
	Point& operator--(); /*--point*/
	Point operator--(int); /*point--*/

	friend std::ostream& operator<<(std::ostream& os, const Point& point);
	friend std::istream& operator>>(std:: istream& is, Point& point);
};

int main()
{
	Point p_1(1, 2);
	Point p_2(3, 4);
	
	p_1++;
	std::cout << p_1[0] << " " << p_1[1] << std::endl;

	return 0;
}

Point::Point() : _x(0), _y(0) {};
Point::Point(double x, double y) : _x(x), _y(y) {};
Point::Point(const Point& other) : _x(other._x), _y(other._y) {};

Point Point::operator+(const Point& other) const
{
	return Point(_x + other._x, _y + other._y);
}

Point Point::operator-(const Point& other) const
{
	return Point(_x - other._x, _y + other._y);
}

Point& Point::operator=(const Point& other)
{
	if (this == &other) return *this;
	_x = other._x;
	_y = other._y;
	return *this;
}

Point& Point::operator=(Point&& other)
{
	if (this == &other) return *this;
	_x = other._x;
	_y = other._y;
	other._x = 0;
	other._y = 0;
	return *this;
}

double& Point::operator[](size_t index)
{
	if (index == 0) return _x;
	if (index == 1) return _y;
}

const double& Point::operator[](size_t index) const
{
	if (index == 0) return _x;
	if (index == 1) return _y;
}

Point& Point::operator++()
{
	++_x;
	++_y;
	return *this;
}

Point Point::operator++(int)
{
	Point temp = *this;
	++_x;
	++_y;
	return temp;
}

Point& Point::operator--() 
{
	--_x;
	--_y;
	return *this;
};

Point Point::operator--(int)
{
	Point temp = *this;
	--_x;
	--_y;
	return temp;
};

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "(" << point._x << ":" << point._y << ")\n";
}

std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point._x >> point._y;
	return is;
}