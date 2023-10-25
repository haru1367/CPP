#include "list.h"
#include <cstdlib>
#include <iostream>

Node::Node(int data, Node* next) {
	this->data = data;
	this->next = next;
}
Node::~Node() {

}

List::List()
{
	Node* p = new Node(-1, nullptr);
	this->ptr = p; // 더미노드에는 아무값이 들어와도 상관x
}

List::~List()
{
	Node* ptr = this->ptr;
	while (ptr) {
		Node* tmp = ptr;
		ptr = ptr->next;
		delete tmp;
	}
}
void List::printList()
{
	Node* ptr = this->ptr->next;
	std::cout << "[";
	while (ptr) {
		std::cout << ptr->data;
		if (ptr->next != nullptr) {
			std::cout << ", ";
		}
		else {
			std::cout << "";
		}
		ptr = ptr->next;
	}
	std::cout<< "]" << std::endl;
}

void List::insertFirstNode(int data)
{
	this->ptr->next = new Node(data, this->ptr->next);
}

void List::insertNode(int prevData, int data)
{
	Node* ptr = this->ptr->next;
	while (ptr) {
		if (ptr->data == prevData) {
			break;
		}
		ptr = ptr->next;
	}
	if (ptr) {
		ptr->next = new Node(data, ptr->next);
	}
}

void List::deleteNode(int data)
{
	Node* ptr = this->ptr->next;
	Node* ptr2 = this->ptr; // ptr뒤에서 따라가는 node
	while (ptr) {
		if (ptr->data == data) {
			break;
		}
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	if (ptr) {
		ptr2->next = ptr->next;
		delete ptr;
	}
}
