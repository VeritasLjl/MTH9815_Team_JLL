// DoublyListIterator.hpp
// Declaration and implementation of the list iterator

#ifndef DOUBLYLISTITERATOR_HPP
#define DOUBLYLISTITERATOR_HPP

#include <memory>
#include "DNode.hpp"
#include "DoublyLinkedList.hpp"

template <typename T>
class DoublyListIterator
{
public:
	std::shared_ptr<DNode<T>> cur;

	DoublyListIterator() : cur(std::make_shared<DNode<T>>()) {}
	DoublyListIterator(DNode<T> _cur) : cur(std::make_shared<DNode<T>>(_cur)) {}
	~DoublyListIterator() {}

	// Return whether there is another element to return in this iterator
	bool HasNext()
	{
		if (cur->next == nullptr)
			return false;
		else
			return true;
	}

	// Return the next element in this iterator
	T& Next()
	{
		cur = cur->next;
		return cur->val;
	}
};

#endif