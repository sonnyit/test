/*
 * hash_table.h
 *
 *  Created on: Jun 2, 2015
 *      Author: MinhNH13
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_
#include "hash_node.h"

#define TABLE_SIZE 1024

template <typename K>
struct KeyHash
{
	unsigned long operator()(const K &key)
	{
		return static_cast<unsigned long>(key % TABLE_SIZE);
	}
};

template <typename K, typename V, typename F=KeyHash<K> >
class HashTable
{
private:
	HashNode<K, V> **hash_table_;
	F hash_func;

public:
	HashTable()
	{
		hash_table_ = new HashNode*[TABLE_SIZE]();
	}

	virtual ~HashTable()
	{
		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			HashNode *entry = hash_table_[i];
			while (entry != nullptr)
			{
				HashNode *prev = entry;
				entry = entry->
			}
		}
	}
};


#endif /* HASH_TABLE_H_ */
