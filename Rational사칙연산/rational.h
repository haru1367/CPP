#ifndef RATIONAL_H

#define RATIONAL_H



class Rational{

public:

	Rational(int num, int den);//생성자

	Rational(int num);

	Rational();

	~Rational();//소멸자

	int number();//get

	int deno();

	void operator=(const Rational &rhs);

	bool operator==(const Rational &rhs);

	Rational operator+(const Rational &rhs);

	Rational operator-(const Rational &rhs);

	Rational operator*(const Rational &rhs);

	Rational operator/(const Rational &rhs);

	void number(int num);

	void deno(int num);

	//set



private:

	int num;   // 분자

	int den;   // 분모



};

#endif
