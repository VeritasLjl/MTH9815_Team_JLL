// Test_Exercise3.hpp
// Test the results of Exercise 3

#ifndef TEST_EXERCISE3_HPP
#define TEST_EXERCISE3_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "HashTable.hpp"

void Test_Exercise3()
{
	MyHasher<int> hasher;
	MyPredicate<int> pred;

	HashTable<int, int> table(std::make_shared<MyHasher<int>>(hasher), 
		std::make_shared<MyPredicate<int>>(pred));

	table.Add(2, 6);
	table.Add(19, 16);
	table.Add(9, 9);
	std::cout << table.Get(2) << std::endl;		// 6
	std::cout << table.Get(19) << std::endl;	// 16
	table.Add(19, 8);
	std::cout << table.Get(19) << std::endl;	// 16
	std::cout << table.Get(10) << std::endl;	// 0
}

#endif