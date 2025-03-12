#include "Fraction.h"

Fraction::Fraction() : _numerator(0), _denominator(1) {};
Fraction::Fraction(int numerator, int denominator)
{
	if (setDenominator(denominator) == 1 || setNumerator(numerator) == 1)
	{
		return;
	}
}

Fraction::Fraction(const Fraction& other) : _numerator(other._numerator), _denominator(other._denominator) {};

bool Fraction::setNumerator(const int numerator)
{
	if (numerator == 0)
	{
		return 1;
	}
	_numerator = numerator;
}

bool Fraction::setDenominator(const int denominator)
{
	if (denominator <= 0)
	{
		return 1;
	}

	_denominator = denominator;

	return 0;
}

void Fraction::Simplify()
{
	int gcd = GCD(_numerator, _denominator);

	_numerator /= gcd;
	_denominator /= gcd;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
	if (fraction._numerator == fraction._denominator)
	{
		os << fraction._numerator;
	}
	else 
	{
		os << fraction._numerator << "/" << fraction._denominator;
	}
	
	return os;
}

Fraction Fraction::operator+(const Fraction& other) 
{
	if (_denominator == other._denominator)
	{
		return Fraction(_numerator + other._numerator, _denominator);
	}

	int lcm = LCM(other);
	int new_numerator = (lcm / _denominator * _numerator) + (lcm / other._denominator * other._numerator);
	int gcd = GCD(new_numerator, lcm);
	

	return Fraction(new_numerator / gcd, lcm / gcd);

}

Fraction Fraction::operator-(const Fraction& other)
{
	if (_denominator == other._denominator)
	{
		return Fraction(_numerator + other._numerator, _denominator);
	}

	int lcm = LCM(other);
	int new_numerator = (lcm / _denominator * _numerator) - (lcm / other._denominator * other._numerator);
	int gcd = GCD(new_numerator, lcm);


	return Fraction(new_numerator / gcd, lcm / gcd);

}

Fraction Fraction::operator*(const Fraction& other)
{
	int new_numerator = _numerator * other._numerator;
	int new_denominator = _denominator * other._denominator;

	int gcd = GCD(new_numerator, new_denominator);

	return Fraction(new_numerator / gcd, new_denominator / gcd);
}

Fraction Fraction::operator/(const Fraction& other)
{
	int new_numerator = _numerator * other._denominator;
	int new_denominator = _denominator * other._numerator;

	int gcd = GCD(new_numerator, new_denominator);

	return Fraction(new_numerator / gcd, new_denominator / gcd);
}

bool Fraction::operator==(const Fraction& other) const {
	return _numerator == other._numerator && _denominator == other._denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
	return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
	return _numerator * other._denominator < other._numerator * _denominator;
}

bool Fraction::operator>(const Fraction& other) const {
	return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
	return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const {
	return !(*this < other);
}

Fraction::operator double() const {
	return (double)_numerator / _denominator;
}