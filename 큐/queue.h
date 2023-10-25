#ifndef QUEUE_H

#define QUEUE_H



class Queue {

private:

	int *array;

	int rear;

	int front;

	int size;

public:

	Queue(int size);

	~Queue();

	void push(int data);

	int pop();

};





#endif
