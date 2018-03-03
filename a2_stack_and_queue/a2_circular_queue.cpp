#include <iostream>
#include "a2_circular_queue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	head_ = 0;
	tail_ = 0;
	capacity_ = 16;
	size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[capacity];
	head_ = 0;
	tail_ = 0;
	capacity_ = capacity;
	size_ = 0;
}

CircularQueue::~CircularQueue()
{
	delete[] items_;
}

bool CircularQueue::empty() const
{
	return !size_;
}

bool CircularQueue::full() const
{
	return size_ == capacity_;
}

int CircularQueue::size() const
{
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(size_ == capacity_)
		return false;
	size_++;
	items_[tail_] = value;
	if(tail_ == capacity_-1)
	{
		tail_ = 0;
		return true;
	}
	tail_++;
	return true;
}

QueueItem CircularQueue::dequeue()
{
	if(!size_)
		return EMPTY_QUEUE;
	size_--;
	if(head_ == capacity_-1)
	{
		head_ = 0;
		return items_[capacity_-1];
	}
	head_++;
	return items_[head_-1];
}

QueueItem CircularQueue::peek() const
{
	if(!size_)
		return EMPTY_QUEUE;
	return items_[head_];
}

void CircularQueue::print() const
{
}

