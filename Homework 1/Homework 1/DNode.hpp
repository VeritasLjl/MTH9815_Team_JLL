// DNode.hpp
// Declaration and implementation of the DNode class

#ifndef DNODE_HPP
#define DNODE_HPP

#include "Node.hpp"
#include <memory>

template <typename T>
class DNode :public Node<T>
{
public:
	T val;		// the value of the node
	std::shared_ptr<DNode<T> > next;    // pointer to the next node
	std::shared_ptr<DNode<T> > prev;    // pointer to the previous node

	DNode(): val(0), next(nullptr), prev(nullptr) {}
	DNode(T _val): val(_val), next(nullptr), prev(nullptr) {}
	~DNode() {}
};

#endif