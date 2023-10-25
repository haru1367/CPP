#include <iostream>

#include "rational.h"



int main(){

	Rational r1(3,4);

	Rational r2(3);

	Rational r3;

	

	r3 = r1;

	

	if (r1 == r3) {

		 std::cout << "r1 and r3 are equal" << std::endl;

	} else {

		std::cout << "r1 and r3 are not equal" << std::endl;

	}

	

	std::cout << r1.number() << "/" << r1.deno() << std::endl;

	std::cout << r3.number() << "/" << r3.deno() << std::endl;

	

	r2 = r1+r3;

	std::cout << r2.number() << "/" << r2.deno() << std::endl;

	r2 = r1-r3;

	std::cout << r2.number() << "/" << r2.deno() << std::endl;

	r2 = r1*r3;

	std::cout << r2.number() << "/" << r2.deno() << std::endl;

	r2 = r1/r3;

	std::cout << r2.number() << "/" << r2.deno() << std::endl;

	

}
