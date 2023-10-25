#include <iostream>

#include "stack.h"



int main()

{

	Stack s1(10), s2(100); // 생성자 사용



	s1.push(100);  //구조체 자료는 인자를 전달할 때 오버헤드를 줄이기 위해 포인터를 쓴다.

	s1.push(200);

	s1.push(300);

	std::cout << "s1 1st pop() : " << s1.pop() <<std::endl;

	std::cout << "s1 2nd pop() : " << s1.pop() <<std::endl;

	std::cout << "s1 3rd pop() : " << s1.pop() <<std::endl;

	

	

	s2.push(900);

	s2.push(800);

	s2.push(700);

	std::cout << "s2 1st pop() : " << s2.pop() <<std::endl;

	std::cout << "s2 2nd pop() : " << s2.pop() <<std::endl;

	std::cout << "s2 3rd pop() : " << s2.pop() <<std::endl;

	

	return 0;

}
