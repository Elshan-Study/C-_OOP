#pragma once
#include <iostream>
class Fraction
{
private:

	int _numerator;
	int _denominator;

	int LCM(const Fraction& other)
	{
		int lcm = _denominator >= other._denominator ? _denominator : other._denominator;
		
		while (lcm % _denominator != 0 || lcm % other._denominator != 0)
		{
			++lcm;
		}

		return lcm;
	}

	int GCD(int numerator, int denominator)
	{
		int gcd = denominator >= numerator ? denominator : numerator;

		while (denominator % gcd != 0 || numerator % gcd != 0)
		{
			--gcd;
		}

		return gcd;
	}

public:

	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(const Fraction& other);

	bool setNumerator(const int numerator);
	bool setDenominator(const int denominator);

	void Simplify();

	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
	Fraction operator+(const Fraction& other);
	Fraction operator-(const Fraction& other);
	Fraction operator*(const Fraction& other);
	Fraction operator/(const Fraction& other);
	bool operator==(const Fraction& other) const;
	bool operator!=(const Fraction& other) const;
	bool operator<(const Fraction& other) const;
	bool operator>(const Fraction& other) const;
	bool operator<=(const Fraction& other) const;
	bool operator>=(const Fraction& other) const;
	operator double() const;
};

