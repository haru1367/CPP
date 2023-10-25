#ifndef COMPLEX_H

#define COMPLEX_H



class Complex{

private:

	double re;   // real part

	double im;   // imaginary part

public:

	Complex(double re, double im);

	Complex(double re);

	Complex();

	~Complex();

	

	double real();

	double imag();

	void real(double re);

	void imag(double im);

	

};

#endif
