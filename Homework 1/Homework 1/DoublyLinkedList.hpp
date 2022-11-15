// DoublyLinkedList.hpp
// Declaration and implementation of the doubly linked list

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <memory>
#include "DNode.hpp"
#include "LinkedList.hpp"

template<typename T>
class DoublyListIterator;

template <typename T>
class DoublyLinkedList :public LinkedList<T>
{
public:
	std::shared_ptr<DNode<T>> head;		// the head of the list
	std::shared_ptr<DNode<T>> tail;		// the tail of the list
	int size;		// the size of the list

	DoublyLinkedList();
	virtual ~DoublyLinkedList();

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
	DoublyListIterator<T> Iterator();

	// Return the size of the list
	int Size();

	// Print all elements of the linked list
	void Print();
};

#endif