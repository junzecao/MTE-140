#include "a1_doubly_linked_list.hpp"
#include <cstddef>
#include<cstdlib>
#include<iostream>

DoublyLinkedList::Node::Node(DataType data)
{
	value = data;
	next = NULL;
	prev = NULL;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
	for(int i = 0; i < size_; i++)
	{
		remove(0);
	}
}

unsigned int DoublyLinkedList::size() const
{
	return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
	return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
	return !size_;
}

bool DoublyLinkedList::full() const
{
	return size_ == CAPACITY;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
	if(!size_)
		return 0;
	if(index >= size_)
		return getNode(size_-1)->value;
	return getNode(index)->value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
	if(!size_)
		return 0;
	for(int i = 0; i < size_; i++)
	{
		if(getNode(i)->value == value)
			return i;
	}
	return size_;
}

void DoublyLinkedList::print() const
{
	if(!size_)
		return;
	for(int i = 0; i < size_; i++)
		std::cout << getNode(i)->value << std::endl;
	std::cout << std::endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
	Node* temp = head_;
	for(int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	return temp;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
	if(index > size_ || index >= CAPACITY)
		return false;
	if(!size_)
	{
		head_ = new Node(value);
		tail_ = head_;
		size_++;
		return true;
	}
	
	if(!index)
	{
		head_->prev = new Node(value);
		head_->prev->next = head_;
		head_ = head_->prev;
		size_++;
		return true;
	}
	
	if(index == size_)
	{
		tail_->next = new Node(value);
		tail_->next->prev = tail_;
		tail_ = tail_->next;
		size_++;
		return true;
	}
	
	Node* temp_next = getNode(index);
	Node* temp_prev = getNode(index-1);
	temp_prev->next = new Node(value);
	temp_next->prev = temp_prev->next;
	temp_prev->next->prev = temp_prev;
	temp_prev->next->next = temp_next;
	size_++;
	return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
	return insert(value, 0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
	return insert(value, size_);
}

bool DoublyLinkedList::remove(unsigned int index)
{
	if(!size_ || index >= size_)
		return false;
	if(size_ == 1)
	{
		delete head_;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		return true;
	}
	if(!index)
	{
		head_ = head_->next;
		delete head_->prev;
		head_->prev = NULL;
		size_--;
		return true;
	}
	if(index+1 == size_)
	{
		tail_ = tail_->prev;
		delete tail_->next;
		tail_->next = NULL;
		size_--;
		return true;
	}
	Node* temp_prev = getNode(index-1);
	Node* temp_next = getNode(index+1);
	delete temp_prev->next;
	temp_prev->next = temp_next;
	temp_next->prev = temp_prev;
	size_--;
	return true;
}

bool DoublyLinkedList::remove_front()
{
	return remove(0);
}

bool DoublyLinkedList::remove_back()
{
	return remove(size_-1);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
	if(index >= size_)
		return false;
	Node* temp = getNode(index);
	temp->value = value;
	return true;
}

