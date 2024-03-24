#include<iostream>
#include "CharStack.h"

CharStack::CharStack(){
	top = NULL;
} // initializam top cu NULL

CharStack::CharStack(char value){
	Node* n = new Node;
	n -> SetValue(value);
	top = n;
} // initializam lista cu o valoare

CharStack::CharStack(const CharStack& stack){
	top = stack.top;
} //constructor de copiere

CharStack& CharStack::operator=(const CharStack& stack){
	top = stack.top;
	return *this;
}//overloading la =

void CharStack::Push(char value){
	if (top == NULL) { //aveam top -> GetNext() daca instantam stack-ul cu cel putin un element
		Node* n = new Node;
		n -> SetValue(value); // daca lista e goala se instanteaza un nod nou, care devine top
		top = n;
	}
	else {
		Node* n = new Node;
		n -> SetNext(top); //nu merge cu &top?
		n -> SetValue(value);
		top = n;
	} //adauga un nod la inceputul stack-ului
}//aceasta metoda tine loc de setter

char CharStack::Pop(){
	char value = top -> GetValue();
	Node* tmp = top;
	top = top -> GetNext(); // vezi daca merge atribuirea asa, s-ar putea sa nu pt ca nu am dat operator overload la Nod*
	delete tmp;	
	return value;
} // aceasta metoda tine loc de getter

char CharStack::Top(){
	char value = top->GetValue();
	return value;
} // returneaza valoarea varfului

bool CharStack::IsEmpty(){
	if(top  == NULL)
		return true;
	return false;
} //verificam daca nodul top a fost initializat si nu este o lista in sine

CharStack::~CharStack(){
	Node* tmp;
        Node* next;
	tmp = top;
	while(tmp -> GetNext() != NULL){
		next = tmp-> GetNext();
		delete tmp;
		Node* tmp = next;
	}
	delete tmp;
	delete next;
} // stergerea listei prin stergerea tuturor nodurilor

std::ostream& operator<<(std::ostream& out, CharStack stack){
	Node* tmp;
	out << stack.Top() << ' ';

	while(tmp -> GetNext() != NULL){
		tmp = tmp -> GetNext();
		out << tmp -> GetValue() << ' ';
	}
	return out;
} // afisarea intregii stive


std::istream& operator>>(std::istream& in, CharStack stack){
	char c;
	in >> c;
	stack.Push(c);
	return in;
} // citirea de la standard in in stack

//TODO: constructor (init si copiere + "=" overloading), << si >>, si FUNCTIE pt citirea a n obiecte

int main(){
	return 0;
}
