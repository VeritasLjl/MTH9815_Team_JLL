// Hasher.hpp
// Declaration and implementation of the hasher class and my own hasher

#ifndef HASHER_HPP
#define HASHER_HPP

template <typename K>
class Hasher
{
public:
	// the pure virtual hasher function to be implemented
	virtual int hash(K key) = 0;
};

// my own hasher function
template <typename K>
class MyHasher :public Hasher<K>
{
	int hash(K key)
	{
		return key % 17;
	}
};

#endif