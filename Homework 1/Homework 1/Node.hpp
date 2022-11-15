// Node.hpp
// Declaration and implementation of the Node class

#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

template <typename T>
class Node
{
public:
	T val;		// the value of the node
	std::shared_ptr<Node<T>> next;		// pointer to the next node

	Node(): val(0), next(nullptr) {}
	Node(T _val): val(_val), next(nullptr) {}		
	~Node() {}
};

#endif