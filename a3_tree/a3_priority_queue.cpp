#include <iostream>
#include "a3_priority_queue.hpp"

typedef PriorityQueue::DataType DataType;
PriorityQueue::PriorityQueue(unsigned int capacity)
{
	heap_ = new DataType[capacity+1];
	capacity_ = capacity;
	size_ = 0;
}


PriorityQueue::~PriorityQueue()
{
	delete heap_;
	heap_ = NULL;
	capacity_ = 0;
	size_ = 0;
}
  

unsigned int PriorityQueue::size() const
{
	return size_;
}

bool PriorityQueue::empty() const
{
	return !size_;
}

bool PriorityQueue::full() const
{
	return size_ == capacity_;
}

void PriorityQueue::print() const
{
	
}

DataType PriorityQueue::max() const
{
	if(!size_)
		return -999;
	return heap_[1];
}

bool PriorityQueue::enqueue(DataType val)
{
	if(size_ == capacity_)
		return false;
	if(size_ == 0)
	{
		heap_[1] = val;
		size_++;
		return true;
	}
	int child = size_+1;
	int parent = child/2;
	heap_[child] = val;
	while(heap_[child] > heap_[parent])
	{
		DataType temp = heap_[child];
		heap_[child] = heap_[parent];
		heap_[parent] = temp;
		child = parent;
		parent /= 2;
	}
	size_++;
	return true;
}

bool PriorityQueue::dequeue()
{
	if(!size_)
		return false;
	heap_[1] = heap_[size_--];
	int index = 1;
	while(2*index <= size_)
	{
		int i = 1;
		int num = 2*index;
		if (num+1 > size_)	//prevents going out-of-bounds
			i = 0;
			
		if(heap_[index]>heap_[num] && heap_[index]>heap_[num+i])
			return true;
			
		if(heap_[num] < heap_[num+i])	//swaps with right child if it's larger
			num += i;
			
		DataType temp = heap_[index];
		heap_[index] = heap_[num];
		heap_[num] = temp;
		index = num;	
	}
	return true;
}

