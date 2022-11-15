// ListIterator.hpp
// Declaration and implementation of the list iterator

#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include <memory>
#include "Node.hpp"
#include "LinkedList.hpp"

template <typename T>
class ListIterator
{
public:
	std::shared_ptr<Node<T>> cur;

	ListIterator(): cur(std::make_shared<Node<T>>()) {}
	ListIterator(Node<T> _cur) : cur(std::make_shared<Node<T>>(_cur)) {}
	~ListIterator() {}

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