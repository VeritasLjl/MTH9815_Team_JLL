// Test_Exercise2.hpp
// Test the results of Exercise 2

#ifndef TEST_EXERCISE2_HPP
#define TEST_EXERCISE2_HPP

#include <iostream>
#include <memory>
#include "DNode.hpp"
#include "DoublyLinkedList.cpp"
#include "ListIterator.hpp"

void Test_Exercise2()
{
	// Test the DNode class
	int val = 5;
	DNode<int> n(val);
	n.next = std::make_shared<DNode<int>>(10);
	n.prev = std::make_shared<DNode<int>>(1);
	std::cout << n.prev->val << ", " << n.val << ", " << n.next->val << std::endl;	// 1, 5, 10
	
	// Test the DoublyLinkedList class
	DoublyLinkedList<int> dl;
	for (int i = 1; i <= 4; ++i)
	{
		dl.Add(i);
	}
	dl.Print();		// 1<->2<->3<->4<->

	val = 100;
	dl.Insert(val, 2);
	dl.Print();		// 1<->2<->100<->3<->4<->
	
	std::cout << dl.Get(3) << std::endl;	// 3
	
	val = 2;
	std::cout << dl.IndexOf(val) << std::endl;		// 1
	val = 10;
	std::cout << dl.IndexOf(val) << std::endl;		// -1
	
	val = 3;
	std::cout << dl.Remove(val) << std::endl;		// 3
	dl.Print();		// 1<->2<->100<->4<->
	
	std::cout << dl.Size() << std::endl;		// 4
	
	// Test the DoublyListIterator class
	auto it = dl.Iterator();
	std::cout << it.HasNext() << std::endl;		// 1
	std::cout << it.Next() << std::endl;		// 1
}

#endif