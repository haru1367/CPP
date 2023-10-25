#include <cstdlib>

#include "queue.h"



Queue::Queue(int size)  

{

	this->array = new int[size];

	this->size = size;

	this->rear = 0;

	this->front = 0;

}



Queue::~Queue() 

{

	delete[] this->array;

}



void Queue::push(int data)

{

	this->array[this->rear] = data;

	++this->rear;

}



int Queue::pop()

{

	int index = this->front;

	++this->front;

	return this->array[index];

}
