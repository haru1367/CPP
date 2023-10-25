#include <cassert> 

#include "stack.h"



Stack::Stack(int size)  //생성자

{

	this ->array = new int[size];

	assert(this->array); 

	this->size = size;

	this->tos = 0;

}





Stack::~Stack()  //소멸자

{

	delete[] this ->array;

}



void Stack::push(int data)

{

	assert(this->tos != this->size);

	this->array[this->tos] = data;

	++this->tos;

}



int Stack::pop()

{

	assert(this->tos!= 0);

	--this->tos;

	return this->array[this->tos];

}
