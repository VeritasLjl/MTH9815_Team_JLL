// HashTable.hpp
// Declaration and implementation of the hash table class

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <memory>
#include <vector>
#include <list>
#include "Hasher.hpp"
#include "EqualityPredicate.hpp"

template <typename K, typename V>
class HashTable
{
public:
	std::shared_ptr<Hasher<K>> hasher;		// the hasher function
	std::shared_ptr<EqualityPredicate<K>> predicate;		// the equality predicate

	// The hash table is implemented as an array of linked lists to handle collision
	std::vector<std::list<std::pair<K, V>>> hashtable;

	HashTable(std::shared_ptr<Hasher<K>> _hasher, std::shared_ptr<EqualityPredicate<K>> _predicate,
		int capacity = 1e5)
	{
		hasher = _hasher;
		predicate = _predicate;
		hashtable = std::vector<std::list<std::pair<K, V>>>(capacity);
	}

	~HashTable() {}

	// Add a key, value pair to the hash table
	void Add(K key, V value)
	{
		std::pair<K, V> pair(key, value);
		int pos = hasher->hash(key);
		std::list<std::pair<K, V>> cur_list = hashtable[pos];
		
		for (auto p : cur_list)
		{
			if (predicate->equals(p.first, key))		// the key already exists
				return;
		}
		hashtable[pos].push_back(pair);
	}

	V Get(K key)		// get the value of the corresponding key
	{
		int pos = hasher->hash(key);
		std::list<std::pair<K, V>> cur_list = hashtable[pos];
		for (auto p : cur_list)
		{
			if (predicate->equals(p.first, key))		// the key is in the table
				return p.second;
		}
		return V();
	}
};

#endif