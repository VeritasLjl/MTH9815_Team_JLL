// LinkedList.hpp
// Declaration of the linkd list class

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <memory>
#include "Node.hpp"

template<typename T>
class ListIterator;

template <typename T>
class LinkedList
{
public:
	std::shared_ptr<Node<T>> head;		// the head of the list
	int size;		// the size of the list

	LinkedList();
	~LinkedList();

	// Add the specified element at the end of the list
	void Add(T& val);

	// Add the specified element at the specified index
	void Insert(T& val, int index);

	// Get the element at the specified index
	T& Get(int index);

	// Retrieve the index of the specified element (-1 if it does not exist in the list)
	int IndexOf(T& value);

	// Remove the element at the specified index and return it
	T& Remove(int index);

	// Return an iterator on this list
	ListIterator<T> Iterator();

	// Return the size of the list
	int Size();

	// Print all elements of the linked list
	void Print();
};

#endif