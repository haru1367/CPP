#pragma once

struct Node {
	int data;
	struct Node* next;
	Node(int data, Node* next);
	~Node();
};

struct List {
private:
	struct Node* ptr;
public:
	List();
	~List();
	void printList();
	void insertFirstNode(int data); // 첫번째 노드에 데이터 추가
	void insertNode(int prevData, int data); // prevdata 뒤의 노드에 데이터 추가
	void deleteNode(int data);  // 데이터 삭제
};
