#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include "a1_doubly_linked_list.hpp"
class Polynomial {
	
	int array_size;
	DoublyLinkedList* d1;
	
public:
	Polynomial(int A[], int size);
	
	Polynomial* add(Polynomial* rhs) const;
	Polynomial* sub(Polynomial* rhs) const;
	Polynomial* mul(Polynomial* rhs) const;
	
	int getValue(int index) const;
	int getArraySize() const;
	void print() const;
	bool isEmpty() const;
	bool isGreaterDegree(Polynomial* rhs) const;
	bool isOddDegree() const;
	bool addLastTerm(int coef);
	bool replaceTerm(int index, int coef);
	
};

#endif

