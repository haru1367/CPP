#include "rational.h"

#include <cassert>



int GCD(int a, int b)

{

    if(b==0)return a;

    else return GCD(b,a%b);

}



Rational::Rational(int num, int den)

{

	assert(den!=0);

	this ->num = num;

	this ->den = den;

}



Rational::Rational(int num)

{

	this->num = num;

	this->den = 1;

}



Rational::Rational()

{

	this->num = 0;

}



Rational::~Rational()

{

}



int Rational::number()

{

	return this->num;

}



int Rational::deno()

{

	return this->den;

}



void Rational::number(int num)

{

	this->num = num;

}



void Rational::deno(int den)

{

	assert(den!=0);

	this->den = den;

}



void Rational::operator=(const Rational &rhs) {

	this->num = rhs.num;

	this->den = rhs.den;

}



bool Rational::operator==(const Rational &rhs) {

	return (this->num == rhs.num && this->den == rhs.den);

}



Rational Rational::operator+(const Rational &rhs) {

	Rational result(this->num * rhs.den + rhs.num * this->den,this->den * rhs.den);

	int gcd = GCD(this->num * rhs.den + rhs.num * this->den,this->den * rhs.den);

	result.num = (this->num * rhs.den + rhs.num * this->den)/gcd;

	result.den = (this->den * rhs.den)/gcd;

	return result;

}



Rational Rational::operator-(const Rational &rhs) {

	Rational result(this->num*rhs.den - rhs.num * this->den,this->den * rhs.den);

	int gcd = GCD(this->num * rhs.den - rhs.num * this->den,this->den * rhs.den);

	result.num = (this->num * rhs.den - rhs.num * this->den)/gcd;

	result.den = (this->den * rhs.den)/gcd;

	return result;

}



Rational Rational::operator*(const Rational &rhs) {

	Rational result(this->num * rhs.num,this->den * rhs.den);

	int gcd = GCD(this->num * rhs.num,this->den * rhs.den);

	result.num = this->num * rhs.num/gcd;

	result.den = this->den * rhs.den/gcd;

	return result;

}



Rational Rational::operator/(const Rational &rhs) {

	assert(rhs.num!=0);

	Rational result(this->num * rhs.den,this->den * rhs.num);

	int gcd = GCD(this->num * rhs.den, this->den * rhs.num);

	result.num = this->num * rhs.den / gcd;

	result.den = this->den * rhs.num / gcd;

	return result;

}
