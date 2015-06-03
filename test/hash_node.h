/*
 * hash_node.h
 *
 *  Created on: Jun 2, 2015
 *      Author: MinhNH13
 */

#ifndef HASH_NODE_H_
#define HASH_NODE_H_

template <typename K, typename V>
class HashNode
{
private:
	K key_;
	V value_;
	HashNode *next_;

public:
	HashNode(const K &key, const V &value) : key_(key), value_(value), next_(nullptr) {}

	virtual ~HashNode()
	{
		if (next_)
		{
			delete next_;
			next_ = nullptr;
		}
	}

	K get_key() const
	{
		return key_;
	}

	V get_value() const
	{
		return value_;
	}

	void set_value(const V &value)
	{
		value = value_;
	}

	HashNode *get_next() const
	{
		return next_;
	}

	void set_next(HashNode *next)
	{
		next_ = next;
	}
};



#endif /* HASH_NODE_H_ */
