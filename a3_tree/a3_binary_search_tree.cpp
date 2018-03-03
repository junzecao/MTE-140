#include <iostream>
#include "a3_binary_search_tree.hpp"

typedef BinarySearchTree::DataType DataType;
BinarySearchTree::Node::Node(DataType newval)
{
	val = newval;
	left = NULL;
	right = NULL;
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
	if(n == NULL)
		return -1;
	return 1 + std::max(getNodeDepth(n->left), getNodeDepth(n->right));
}

BinarySearchTree::BinarySearchTree()
{
	root_ = NULL;
	size_ = 0;
}

BinarySearchTree::~BinarySearchTree()
{
	while(size_)
		remove(root_->val);
}

unsigned int BinarySearchTree::size() const
{
	return size_;
}

DataType BinarySearchTree::max() const
{
	Node* temp = root_;
	while(temp->right != NULL)
		temp = temp->right;
	return temp->val;
}

DataType BinarySearchTree::min() const
{
	Node* temp = root_;
	while(temp->left != NULL)
		temp = temp->left;
	return temp->val;
}

unsigned int BinarySearchTree::depth() const
{
	return getNodeDepth(root_);
}

bool BinarySearchTree::exists(DataType val) const
{
	Node* temp = root_;
	while(temp != NULL)
	{
		if(val == temp->val)
			return true;
		else if(val < temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode()
{
	return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress()
{
	return &root_;
}

bool BinarySearchTree::insert(DataType val)
{
	if(root_ == NULL)
	{
		root_ = new Node(val);
		size_++;
		updateNodeBalance(root_);
		return true;
	}
	Node* temp = root_;
	while(true)
	{
		if(val == temp->val)
			return false;
		if(val < temp->val)
		{
			if(temp->left == NULL)
			{
				temp->left = new Node(val);
				size_++;
				updateNodeBalance(root_);
				return true;
			}
			temp = temp->left;
		}
		else
		{
			if(temp->right == NULL)
			{
				temp->right = new Node(val);
				size_++;
				updateNodeBalance(root_);
				return true;
			}
			temp = temp->right;
		}
	}
	
}

bool BinarySearchTree::remove(DataType val)
{
	if(!exists(val))
		return false;
	
	if(size_ == 1)
	{
		delete root_;
		root_ = NULL;
		size_--;
		updateNodeBalance(root_);
		return true;
	}
	
	Node* temp = root_;
	Node* parent;
	while(temp->val != val)
	{
		parent = temp;
		if(val < temp->val)
			temp = temp->left;
		else
			temp = temp->right;
	}
	
	if(temp->left != NULL && temp->right != NULL)
	{
		Node* max;
		while(temp->left != NULL)
		{
			parent = temp;
			max = temp->left;
			while(max->right != NULL)
			{
				parent = max;
				max = max->right;
			}
			temp->val = max->val;
			temp = max;
		}
	}
	
	if(temp->left == NULL && temp->right == NULL)
	{
		delete temp;
		if(parent->left != NULL && parent->left == temp)
			parent->left = NULL;
		else
			parent->right = NULL;
		size_--;
		updateNodeBalance(root_);
		return true;
	}
	
	if(temp->left != NULL)
	{
		temp->val = temp->left->val;
		temp->right = temp->left->right;
		Node* once = temp->left;
		temp->left = temp->left->left;
		delete once;
	}
	else
	{
		temp->val = temp->right->val;
		temp->left = temp->right->left;
		Node* once = temp->right;
		temp->right = temp->right->right;
		delete once;
	}
	size_--;
	updateNodeBalance(root_);
	return true;
}

void BinarySearchTree::updateNodeBalance(Node* n)
{
	if(n == NULL)
		return;
	n->avlBalance = getNodeDepth(n->left) - getNodeDepth(n->right);
	updateNodeBalance(n->left);
	updateNodeBalance(n->right);
}

