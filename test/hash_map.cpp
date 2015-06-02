/*
 * hash_map.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: MinhNH13
 */
#include "hash_map.h"

template <typename K, typename V>
HashMap<K, V>::HashMap()
{
	_hash_map = new HashNode<K, V> *[TABLE_SIZE]();
}

template <typename K, typename V>
HashMap<K, V>::~HashMap()
{
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		HashNode<K, V> *entry = _hash_map[i];
		while (entry != nullptr)
		{
			HashNode<K, V> *prev = entry;
			entry = entry->get_next();
			delete prev;
		}
		_hash_map[i] = nullptr;
	}
	delete []_hash_map;
}

template <typename K, typename V>
bool HashMap<K, V>::get(const K &key, V &value)
{
	HashNode<K, V> *entry;
	KeyHash<K> hash_func;
	unsigned long hash_value = hash_func(key);
	entry = _hash_map[hash_value];

	while (entry != nullptr)
	{
		if (entry->get_key() == key)
		{
			value = entry->get_value();
			return true;
		}
		entry = entry->get_next();
	}
	return false;
}

template <typename K, typename V>
void HashMap<K, V>::put(const K &key, const V &value)
{
	KeyHash<K> hash_func;
	unsigned long hash_value = hash_func(key);
	HashNode<K, V> *entry, *prev;
	entry = _hash_map[hash_value];
	prev = nullptr;

	while (entry != nullptr && entry->get_key() != key)
	{
		prev = entry;
		entry = entry->get_next();
	}

	if (entry == nullptr)
	{
		entry = new HashNode<K, V>(key, value);
		if (prev == nullptr)
			_hash_map[hash_value] = entry;
		else
			prev->set_next(entry);
	}
	else
	{
		// update value
		entry->set_value(value);
	}
}

template <typename K, typename V>
void HashMap<K, V>::remove(const K &key)
{
	KeyHash<K> hash_func;
	unsigned long hash_value = hash_func(key);
	HashNode<K, V> *entry, *prev;
	entry = _hash_map[hash_value];
	prev = nullptr;

	while (entry != nullptr && entry->get_key() != key)
	{
		prev = entry;
		entry = entry->get_next();
	}

	if (entry != nullptr && entry->get_key() == key && prev != nullptr)
	{
		prev->set_next(entry->get_next());
	}
	else if (entry != nullptr && prev == nullptr)
	{
		delete entry;
		_hash_map[hash_value] = nullptr;
	}
}

