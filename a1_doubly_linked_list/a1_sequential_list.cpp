#include "a1_sequential_list.hpp"
#include<cstdlib>
#include<iostream>

SequentialList::SequentialList(unsigned int cap)
{
	data_ = new DataType[cap];
	capacity_ = cap;
	size_ = 0;
}

SequentialList::~SequentialList()
{
	delete[] data_;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::empty() const
{
	return !size_;
}

bool SequentialList::full() const
{
	return size_ == capacity_;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(index > (size_ - 2))
		return data_[size_ - 1];
	return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
	int i = 0; 
	while(i < size_)
	{
		if(data_[i] == val)
			return i;
		i++; 
	}
	return size_;
}

void SequentialList::print() const
{
	for(int i = 0; i < size_; i++)
	{
		std::cout << data_[i] << std::endl; 
	}
	std::cout << std:: endl;
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(size_ >= capacity_ || index > size_)
		return false;
	/*
	for(int i = (size_-1); i >= index; i--)
	{
		std::cout << size_;
		data_[i+1] = data_[i];
		std::cout << "size::::" << size_ << std::endl;
		print();
	}
	*/
	for(int i = size_; i >= (index+1); i--)
		data_[i] = data_[i-1];
	data_[index] = val;
	size_++;
	//std::cout << "size::::" << size_ << std::endl;
	//print();
	return true;
}

bool SequentialList::insert_front(DataType val)
{
	return insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
	return insert(val, size_);
}

bool SequentialList::remove(unsigned int index)
{
	//std::cout << (index >= size_ || !size_) << std::endl;
	if(index >= size_ || !size_)
		return false;
	for(int i = index; i < (size_-1); i++)
		data_[i] = data_[i+1];
	size_--;
	//std::cout << "size::::" << size_ << std::endl;
	//print();
	return true;
}

bool SequentialList::remove_front()
{
	return remove(0);
}

bool SequentialList::remove_back()
{
	return remove(size_-1);
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(index >= size_)
		return false;
	data_[index] = val;
	return true;
}

