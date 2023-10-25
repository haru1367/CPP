#ifndef STACK_H

#define STACK_H



class Stack {

private:

	int *array;

	int tos;

	int size;

public:

	Stack(int size); // constructor(생성자)는 함수이름을 구조체 이름으로 설정한다. 타입은 x (c언어에서 initstack함수)

	~Stack();        // destructor (소멸자) (c언어에서 cleanupstack함수)

	void push(int data);

	int pop();

};



#endif
