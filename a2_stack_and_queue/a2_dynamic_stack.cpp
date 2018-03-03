#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	items_ = new StackItem[16];
	capacity_ = 16;
	size_ = 0;
	init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	items_ = new StackItem[capacity];
	capacity_ = capacity;
	size_ = 0;
	init_capacity_ = capacity;
}

DynamicStack::~DynamicStack()
{
	delete[] items_;
}

bool DynamicStack::empty() const
{
	return !size_;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_ < capacity_)
	{
		items_[size_] = value;
		size_++;
		return;
	}
	StackItem* temp = new StackItem[capacity_*2];
	for(int i = 0; i < size_; i++)
		temp[i] = items_[i];
	temp[size_] = value;
	size_++;
	capacity_ *= 2;
	delete[] items_;
	items_ = temp;
}

StackItem DynamicStack::pop()
{
	if(!size_)
		return EMPTY_STACK;
	if(size_ <= capacity_*0.25 && capacity_*0.5 >= init_capacity_)
	{
		StackItem* temp = new StackItem[capacity_/2];
		for(int i = 0; i < size_; i++)
			temp[i] = items_[i];
		capacity_ /= 2;
		delete[] items_;
		items_ = temp;
	}
	size_--;
	return items_[size_];
}

StackItem DynamicStack::peek() const
{
	if(!size_)
		return EMPTY_STACK;
	return items_[size_-1];
}

void DynamicStack::print() const
{
}

