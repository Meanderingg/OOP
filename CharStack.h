#include<iostream>
#include "Node.h"

class CharStack{
	Node* top;

public:
	CharStack();
	CharStack(char value); // init cu valoare pt top

	CharStack(const CharStack& stack);
       	CharStack& operator=(const CharStack& stack);


	void Push(char value); //pune valoarea pe stack
	char Pop(); //returneaza valoarea si o sterge
	char Top(); // valoarea varfului
	bool IsEmpty(); //verifica daca stack-ul e gol

	~CharStack();

	friend std::ostream& operator<<(std::ostream &out, CharStack& stack);
	//friend istream& operator>>(instream &in, CharStack& stack);

};

