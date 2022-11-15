// Test_Exercise1.hpp
// Test the results of Exercise 1

#ifndef TEST_EXERCISE1_HPP
#define TEST_EXERCISE1_HPP

#include <iostream>
#include <memory>
#include "Node.hpp"
#include "LinkedList.cpp"
#include "ListIterator.hpp"

void Test_Exercise1()
{
	// Test the Node class
	int val = 5;
	Node<int> n(val);
	n.next = std::make_shared<Node<int>>(10);
	std::cout << n.val << ", " << n.next->val << std::endl;		// 5, 10

	// Test the LinkedList class
	LinkedList<int> ll;
	for (int i = 1; i <= 4; ++i)
	{
		ll.Add(i);
	}
	ll.Print();		// 1->2->3->4->

	val = 100;
	ll.Insert(val, 2);
	ll.Print();		// 1->2->100->3->4->

	std::cout << ll.Get(3) << std::endl;	// 3
	
	val = 2;
	std::cout << ll.IndexOf(val) << std::endl;		// 1
	val = 10;
	std::cout << ll.IndexOf(val) << std::endl;		// -1

	val = 3;
	std::cout << ll.Remove(val) << std::endl;		// 3
	ll.Print();		// 1->2->100->4->

	std::cout << ll.Size() << std::endl;		// 4

	// Test the ListIterator class
	auto it = ll.Iterator();
	std::cout << it.HasNext() << std::endl;		// 1
	std::cout << it.Next() << std::endl;		// 1
}

#endif