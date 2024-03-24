#include<iostream>

#include "Node.h"

Node::Node(){
	next = NULL;
	info[0] = '\0';
}//constructor de init fara parametrii

Node::Node(char info, Node* next){
	this -> info[0] = info;
       	this -> next = next;
}
//initializam cu parametrii

Node::Node(Node* next){
	info[0] = 'a';
	this -> next = next;
}//constructori de intializere cu parametrii, default a pt info

Node::Node(char x){
	info[0] = x;
	next = NULL;
}//constructori de intializere cu parametru pentru valuare


Node::Node(const Node& Node){
	this -> info[0] = Node.info[0];
	this -> next = Node.next;
} //constructor de copiere

Node& Node::operator=(const Node& node){ 
	info[0] = node.info[0];
	next = node.next;
	return *this;
} //operator overloading la =

void Node::SetNext(Node* next){
	this -> next = next;
} // setter pt pointer

void Node::SetValue(char x){
	info[0] = x;
} // setter pt charactere
char Node::GetValue(){
	return info[0];
} //getter pt caractere

Node* Node::GetNext(){
	return next;
} //getter pt pointer

Node::~Node(){
	//delete next; 
} // destrctor
/*
int main() {
	Node a;
	std::cout<<a.GetValue()<<" ar trebui sa fie 0\n";
	a.SetValue('c');
	Node b(a);
	std::cout<<b.GetValue()<<" ar trebui sa fie c \n";
	Node c('d');
	Node* ptr;
	ptr = &a;
	c.SetNext(ptr);
	std::cout<<c.GetNext()->GetValue()<<" valoarea copiata trebuia sa fie c\n";
	Node d(&c);
	std::cout<<d.GetNext()->GetValue()<<" valoarea copiata trebuia sa fie d\n";
	c=a; // aceste trei linii de cod dau ori free(): invalid pointer ori double free or corruption(out)
	std::cout<<c.GetValue()<<" ar trebui sa fie c \n";
	return 0;
}
*/
