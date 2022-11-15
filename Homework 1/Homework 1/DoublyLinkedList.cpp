// DoublyLinkedList.cpp
// Implementation of the doubly linkd list class

#include <iostream>
#include <memory>
#include <stdexcept>
#include "DNode.hpp"
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyListIterator.hpp"

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = std::make_shared<DNode<T>>();
	tail = std::make_shared<DNode<T>>();
	size = 0;
	head->next = tail;
	tail->prev = head;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {}

// Add the specified element at the end of the list
template <typename T>
void DoublyLinkedList<T>::Add(T& val)
{
	DNode<T> new_node(val);
	tail->prev->next = std::make_shared<DNode<T>>(new_node);
	tail->prev->next->next = tail;
	tail->prev = tail->prev->next;
	size++;
	return;
}

// Add the specified element at the specified index
template <typename T>
void DoublyLinkedList<T>::Insert(T& val, int index)
{
	if (index >= size || index < 0)
	{
		throw std::out_of_range("Insert index out of range");
		return;
	}

	auto cur = head;
	DNode<T> new_node(val);
	for (int i = 0; i < index; ++i)
	{
		cur = cur->next;
	}
	auto temp = cur->next;
	cur->next = std::make_shared<DNode<T>>(new_node);
	cur->next->next = temp;
	temp->prev = cur->next;
	cur->next->prev = cur;
	size++;
	return;
}

// Get the element at the specified index
template <typename T>
T& DoublyLinkedList<T>::Get(int index)
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
int DoublyLinkedList<T>::IndexOf(T& value)
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
T& DoublyLinkedList<T>::Remove(int index)
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
	cur->next->prev = cur;
	size--;
	return temp->val;
}

// Return an iterator on this list
template <typename T>
DoublyListIterator<T> DoublyLinkedList<T>::Iterator()
{
	return DoublyListIterator<T>(*head);
}

// Return the size of the list
template <typename T>
int DoublyLinkedList<T>::Size()
{
	return size;
}

// Print all elements of the linked list
template <typename T>
void DoublyLinkedList<T>::Print()
{
	auto it = head;
	while (it->next != tail)
	{
		it = it->next;
		std::cout << it->val << "<->";
	}
	std::cout << std::endl;
	return;
}

