#include "a1_polynomial.hpp"
#include<cstdlib>
#include<iostream>

Polynomial::Polynomial(int A[], int size)
{
	array_size = size;
	d1 = new DoublyLinkedList();
	for(int i = 0; i < size; i++)
		d1->insert_back(A[i]);
}

Polynomial* Polynomial::add(Polynomial* rhs) const
{
	int max = std::max(array_size, rhs->getArraySize());
	int array[max] = {0};
	for(int i = 0; i < array_size; i++)
		array[i] += d1->select(i);
	for(int i = 0; i < rhs->getArraySize(); i++)
		array[i] += rhs->d1->select(i);
	
	return new Polynomial(array, max);
}


Polynomial* Polynomial::sub(Polynomial* rhs) const
{
	int max = std::max(array_size, rhs->getArraySize());
	int array[max] = {0};
	for(int i = 0; i < array_size; i++)
		array[i] += d1->select(i);
	for(int i = 0; i < rhs->getArraySize(); i++)
		array[i] -= rhs->d1->select(i);
	
	return new Polynomial(array, max);
}


Polynomial* Polynomial::mul(Polynomial* rhs) const
{
	int max = array_size + rhs->getArraySize();
	int array[max-1] = {0};
	for(int i = 0; i < array_size; i++)
	{
		for(int j = 0; j < rhs->getArraySize(); j++)
			array[i+j] += d1->select(i) * rhs->d1->select(j);
	}
	return new Polynomial(array, max-1);
}


int Polynomial::getArraySize() const
{
	return array_size;
}

void Polynomial::print() const
{
	std::cout << "The array size is " << array_size << std::endl;
	for(int i = 0; i < array_size; i++)
		std::cout << "x^" << i << " " << d1->select(i) << std::endl;
	std::cout << std::endl;
}

bool Polynomial::isEmpty() const
{
	return !array_size;
}

int Polynomial::getValue(int index) const
{
	if(index >= array_size)
		return -1000;
	return d1->select(index);
}

bool Polynomial::isGreaterDegree(Polynomial* rhs) const
{
	return array_size > rhs->getArraySize();
}

bool Polynomial::isOddDegree() const
{
	return !(array_size%2);
}

bool Polynomial::addLastTerm(int coef)
{
	if(d1->insert_back(coef))
	{
		array_size++;
		return true;
	}
	return false;
}

bool Polynomial::replaceTerm(int index, int coef)
{
	return d1->replace(index, coef);
}

