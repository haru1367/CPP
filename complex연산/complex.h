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

	void operator=(const Complex &rhs);

	bool operator==(const Complex &rhs);

	Complex operator+(const Complex &rhs);

	Complex operator-(const Complex &rhs);

	

};

//Complex operator+(Complex lhs, Complex rhs);

//Complex operator+(const Complex *pc1, const Complex *pc2);

//Complex operator+(Complex &r1, Complex &r2);



#endif
