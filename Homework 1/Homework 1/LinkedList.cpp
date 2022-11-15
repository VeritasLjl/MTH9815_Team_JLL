// LinkedList.cpp
// Implementation of the linkd list class

#include <iostream>
#include <memory>
#include <stdexcept>
#include "Node.hpp"
#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList(): head(std::make_shared<Node<T>>()), size(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {}

// Add the specified element at the end of the list
template <typename T>
void LinkedList<T>::Add(T& val)
{
	auto cur = head;
	Node<T> new_node(val);
	for (int i = 0; i < size; ++i)
	{
		cur = cur->next;
	}
	cur->next = std::make_shared<Node<T>>(new_node);
	size++;
	return;
}

// Add the specified element at the specified index
template <typename T>
void LinkedList<T>::Insert(T& val, int index)
{
	if (index >= size || index < 0) 
	{
		throw std::out_of_range("Insert index out of range");
		return;
	}

	auto cur = head;
	Node<T> new_node(val);
	for (int i = 0; i < index; ++i)
	{
		cur = cur->next;
	}
	auto temp = cur->next;
	cur->next = std::make_shared<Node<T>>(new_node);
	cur->next->next = temp;
	size++;
	return;
}

// Get the element at the specified index
template <typename T>
T& LinkedList<T>::Get(int index)
{
	if (index >= size || index < 0) 
	{
		throw std::out_of_range("Get index out of range");
	}

	auto cur = head;
	for (int i = 0; i < index; ++i)
	{
		cur = cur->next;
	}
	return cur->next->val;
}

// Retrieve the index of the specified element (-1 if it does not exist in the list)
template <typename T>
int LinkedList<T>::IndexOf(T& value)
{
	auto cur = head;
	int index = 0;
	while (cur->next) 
	{
		cur = cur->next;
		if (cur->val == value) 
		{
			return index;
		}
		++index;
	}
	return -1;
}

// Remove the element at the specified index and return it
template <typename T>
T& LinkedList<T>::Remove(int index) 
{
	if (index >= size || index < 0) 
	{
		throw std::out_of_range("Remove index out of range");
	}

	auto cur = head;
	for (int i = 0; i < index; ++i) 
	{
		cur = cur->next;
	}
	auto temp = cur->next;
	cur->next = cur->next->next;
	--size;
	return temp->val;
}

// Return an iterator on this list
template <typename T>
ListIterator<T> LinkedList<T>::Iterator()
{
	return ListIterator<T>(*head);
}

// Return the size of the list
template <typename T>
int LinkedList<T>::Size() 
{
	return size;
}

// Print all elements of the linked list
template <typename T>
void LinkedList<T>::Print()
{
	auto it = this->Iterator();
	while (it.HasNext()) 
	{
		std::cout << it.Next() << "->";
	}
	std::cout << std::endl;
	return;
}

