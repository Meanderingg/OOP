#include<iostream>

class Node{
	char info[1];
	Node* next;

public:
	Node();
	Node(Node* next);
	Node(char x);
	Node(char info, Node* next); //constructori de init

	Node(const Node& Node); // constructor de copiere
	Node operator=(const Node& node);

	void SetNext(Node* next);
	void SetChar(char x);
	char GetNode(); //setter si getter

	~Node();

};
