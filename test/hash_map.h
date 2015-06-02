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

template<typename K>
struct KeyHash {
	unsigned long operator()(const K &key) const {
		return static_cast<unsigned long>(key) % TABLE_SIZE;
	}
};

template<typename K, typename V, typename F = KeyHash<K>>
class HashMap {
private:
	HashNode<K, V> **_hash_map;
	F hash_func;
public:
	HashMap() {
		_hash_map = new HashNode<K, V> *[TABLE_SIZE]();
	}

	virtual ~HashMap() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			HashNode<K, V> *entry = _hash_map[i];
			while (entry != nullptr) {
				HashNode<K, V> *prev = entry;
				entry = entry->get_next();
				delete prev;
			}
			_hash_map[i] = nullptr;
		}
		delete[] _hash_map;
	}

	bool get(const K &key, V &value) {
		HashNode<K, V> *entry;
		unsigned long hash_value = hash_func(key);
		entry = _hash_map[hash_value];

		while (entry != nullptr) {
			if (entry->get_key() == key) {
				value = entry->get_value();
				return true;
			}
			entry = entry->get_next();
		}
		return false;
	}

	void put(const K &key, const V &value) {
		unsigned long hash_value = hash_func(key);
		HashNode<K, V> *entry, *prev;
		entry = _hash_map[hash_value];
		prev = nullptr;

		while (entry != nullptr && entry->get_key() != key) {
			prev = entry;
			entry = entry->get_next();
		}

		if (entry == nullptr) {
			entry = new HashNode<K, V>(key, value);
			if (prev == nullptr)
				_hash_map[hash_value] = entry;
			else
				prev->set_next(entry);
		} else {
			// update value
			entry->set_value(value);
		}
	}

	void remove(const K &key) {
		unsigned long hash_value = hash_func(key);
		HashNode<K, V> *entry, *prev;
		entry = _hash_map[hash_value];
		prev = nullptr;

		while (entry != nullptr && entry->get_key() != key) {
			prev = entry;
			entry = entry->get_next();
		}

		if (entry != nullptr && entry->get_key() == key && prev != nullptr) {
			prev->set_next(entry->get_next());
		} else if (entry != nullptr && prev == nullptr) {
			delete entry;
			_hash_map[hash_value] = nullptr;
		}
	}
};

struct MyKeyHash {
	unsigned long operator()(const int &k) const
	{
		return k % 10;
	}
};

#endif /* HASH_MAP_H_ */
