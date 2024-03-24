#include<iostream>

class Node{
	char info[1]; //merge cu char info?
	Node* next;

public:
	Node();
	Node(Node* next);
	Node(char x);
	Node(char info, Node* next); //constructori de init

	Node(const Node& Node); // constructor de copiere
	Node& operator=(const Node& node);

	void SetNext(Node* next);
	void SetValue(char x);
	char GetValue(); //setter si getter
	Node* GetNext(); // getter pt pointer-ul la urm valoare

	~Node();

};
