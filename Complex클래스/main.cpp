#include <iostream>

#include "complex.h"



int main()

{

	Complex c1(3.0,4.0); // 3.0 + 4.0i

	Complex c2(3.0);     // 3.0 + 0i

	Complex c3;			  // 0 + 0i

	

	c3.real(c1.real());

	c3.imag(c1.imag());

	

	std::cout << "(" << c1.real() << ", " << c1.imag() << "i)" << std::endl;

	std::cout << "(" << c2.real() << ", " << c2.imag() << "i)" << std::endl;

	std::cout << "(" << c3.real() << ", " << c3.imag() << "i)" << std::endl;

	return 0;

}
