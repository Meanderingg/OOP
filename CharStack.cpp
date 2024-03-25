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
	if(stack.top == NULL)
		top = stack.top;
	else{
	Node* tmp;
	tmp = stack.top;
	Node* back = new Node;
	back -> SetValue(stack.top -> GetValue()) ;
	top  = back;
	while(tmp -> GetNext() != NULL){
		tmp = tmp -> GetNext();
		Node* n = new Node;
		back -> SetNext(n);
		n -> SetValue(tmp -> GetValue());
		back = n;
		back -> SetNext(NULL);
	}
	}

} //constructor de copiere, parcurege lista elem cu elem si o creeaza pe a doua elem cu elem

CharStack& CharStack::operator=(const CharStack& stack){
	if(stack.top == NULL)
		top = stack.top;
	else{
	Node* tmp;
	tmp = stack.top;
	Node* back = new Node;
	back -> SetValue(stack.top -> GetValue()) ;
	top  = back;
	while(tmp -> GetNext() != NULL){
		tmp = tmp -> GetNext();
		Node* n = new Node;
		back -> SetNext(n);
		n -> SetValue(tmp -> GetValue());
		back = n;
		back -> SetNext(NULL);
	}
	}
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
		n ->SetNext(top); //nu merge cu &top?
		n -> SetValue(value);
		top = n;
	} //adauga un nod la inceputul stack-ului
}//aceasta metoda tine loc de setter

char CharStack::Pop(){
	char value = top -> GetValue();
	Node* tmp = top;
	top = top -> GetNext(); 
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
	if(top == NULL || top ->GetNext() == NULL) //altfel dadea erori
		delete top;
	else{
	Node* tmp;
	tmp = top;
	while(top -> GetNext() != NULL){
		top = top -> GetNext();
		delete tmp;
	       	tmp = top;
	}
	}
} // stergerea listei prin stergerea tuturor nodurilor

std::ostream& operator<<(std::ostream& out, CharStack& stack){
	Node* tmp;
	tmp = stack.top;
	out << tmp -> GetValue();
	while(tmp -> GetNext() != NULL){
		tmp = tmp -> GetNext();
		out << tmp -> GetValue();
	}
	return out;
} // afisarea intregii stive


std::istream& operator>>(std::istream& in, CharStack& stack){
	char c[101];
	in >> c;
	int i = 0;
	while(c[i] != '\0'){
		stack.Push(c[i]);
		i++;
	}
	return in;
} // citirea de la standard in in stack, maxim 100 de caractere in un cuvant

void ReadPrintN(int n){
	CharStack sir[n]; //instantam un array de stak-uri
	for(int i = 0; i<n; i++){
		CharStack s;
		std::cin>>sir[i];
	}
	for(int i=0; i<n; i++){
		std::cout<<sir[i]<<'\n';
	}
}
		

int main(){
	/* //sectiunea de testare a metodelor
	CharStack s;
	s.Push('v');
	std::cout<<s<<'\n'; //merge cout pt un sg char, merge push
	s.Push('u');
	std::cout<<s<<'\n'; //merge sa dau cout la mai multe noduri, destructor-ul merge pt ambele cazuri acum 
	s.Push('c');
	//std::cin>>s; //merge
	//std::cin>>s>>s; //merge si asa
	std::cout<<s<<'\n';//merge cin, cout	
	//s.Pop();
	//std::cout<<s<<'\n'; //merge si pop
	CharStack a(s);
	std::cout<<a<<'\n';
	CharStack cuv;
	std::cout<<cuv.IsEmpty()<<'\n';//merge si IsEmpty
	cuv = s;
	std::cout<<cuv<<'\n'; //merg constructorii de copiere si overloading la =
	std::cout<<cuv.Top()<<'\n';//merge si Top()
	*/	

	CharStack l;
	std::cin>>l;	
	std::cout<<l<<'\n'; 

	/*char chr[4] = "luc";
	CharStack inversare;
	for(int i =0; i<4; i++){
		inversare.Push(chr[i]);
	}
	std::cout<<inversare; //inversarea pt un char declarat in program
	
	int n;
	std::cin>>n;
	ReadPrintN(n); //verificarea functiei pt citirea, memorarea si afisarea a n stack-uri
	*/
	
	return 0;
}

