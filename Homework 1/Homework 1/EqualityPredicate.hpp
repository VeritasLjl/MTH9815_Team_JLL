// EqualityPredicate.hpp
// Declaration and implementation of the predicator and my own predicator

#ifndef EQUALITYPREDICATE_HPP
#define EQUALITYPREDICATE_HPP

template <typename K>
class EqualityPredicate
{
public:
	// the pure virtual predicate to be implemented
	virtual bool equals(K key1, K key2) = 0;
};

// my own predicate
template <typename K>
class MyPredicate :public EqualityPredicate<K>
{
public:
	bool equals(K key1, K key2)
	{
		return key1 == key2;
	}
};

#endif