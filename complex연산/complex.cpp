#include "complex.h"



//member function



/*Complex operator+(Complex lhs, Complex rhs){

	Complex result(lhs.real() + rhs.real(),lhs.imag() + rhs.imag());

	return result;

}*/



/*Complex operator+(const Complex *pc1, const Complex *pc2){

	Complex result(pc1->real() + pc2 ->real(), pc1->imag() + pc2->imag());

	return result;

}*/



/*Complex operator+(Complex &r1, Complex &r2){

	Complex result(r1.real()+r2.real(),r1.imag()+r2.imag());

	return result;

}*/



Complex::Complex()

{

	this->re = 0.0;

	this->im = 0.0;

}



Complex::Complex(double re)

{

	this->re = re;

	this->im = 0.0;	

}



Complex::Complex(double re, double im)

{

	this->re = re;

	this->im = im;

}



Complex::~Complex()

{	

}



void Complex::operator=(const Complex& rhs) {

	this->re = rhs.re;

	this->im = rhs.im;

}



bool Complex::operator==(const Complex &rhs) {

	/*if (this->re == rhs.re && this->im == rhs.im){

		return true;

	} else {

		return false;

	}*/

	return (this->re == rhs.re && this->im == rhs.im);

}



double Complex::real()

{

	return this->re;

}



double Complex::imag()

{

	return this->im;

}



void Complex::real(double re) 

{

	this->re = re;

}



void Complex::imag(double im)

{

	this->im = im;

}





Complex Complex::operator+(const Complex &rhs) {

	Complex result(this->re  + rhs.re, this->im + rhs.im);

	return result;

}



Complex Complex::operator-(const Complex &rhs){

	Complex result(this->real()-rhs.re, this->imag()-rhs.im);

	return result;

}
