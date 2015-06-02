/*
 * hash_map.h
 *
 *  Created on: Jun 1, 2015
 *      Author: MinhNH13
 */

#ifndef HASH_MAP_H_
#define HASH_MAP_H_
#include "hash_node.h"
#include <string>

static const int TABLE_SIZE = 1024;

template <typename K>
struct KeyHash {
	unsigned long operator()(const K &key) const
	{
		return static_cast<unsigned long>(key) % TABLE_SIZE;
	}
};
template struct KeyHash<int>;

template <typename K, typename V>
class HashMap
{
private:
	HashNode<K, V> **_hash_map;
public:
	HashMap();
	virtual ~HashMap();

	bool get(const K &key, V &value);
	void put(const K &key, const V &value);
	void remove(const K &key);
};

template class HashMap<int, std::string>;

#endif /* HASH_MAP_H_ */
