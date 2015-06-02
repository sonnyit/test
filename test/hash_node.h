/*
 * hash_node.h
 *
 *  Created on: Jun 1, 2015
 *      Author: MinhNH13
 */

#ifndef HASH_NODE_H_
#define HASH_NODE_H_

template <typename K, typename V>
class HashNode
{
private:
	HashNode *_next;
	K _key;
	V _value;
public:
	HashNode(const K &key, const V &value) :
		_key(key), _value(value), _next(nullptr) {};

	K get_key() const
	{
		return _key;
	}

	V get_value() const
	{
		return _value;
	}

	void set_value(const V &value)
	{
		_value = value;
	}

	HashNode *get_next() const
	{
		return _next;
	}

	void set_next(HashNode *next)
	{
		_next = next;
	}
};



#endif /* HASH_NODE_H_ */
