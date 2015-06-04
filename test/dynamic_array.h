/*
 * dynamic_array.h
 *
 *  Created on: Jun 4, 2015
 *      Author: MinhNH13
 */

#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_
#include <cassert>

class DynamicArray
{
private:
	int size_;
	int capacity_;
	int *storage_;

	void pack()
	{
		if (size_ < capacity_ / 2)
		{
			int new_capacity = (size_ * 3) / 2 + 1;
			set_capacity(new_capacity);
		}
	}

	void trim()
	{
		set_capacity(size_);
	}

public:
	DynamicArray() {
		capacity_ = 10;
		size_ = 0;
		storage_ = new int[capacity_];
	}

	DynamicArray(int capacity)
	{
		capacity_ = capacity;
		size_ = 0;
		storage_ = new int[capacity_];
	}

	virtual ~DynamicArray()
	{
		delete []storage_;
		storage_ = nullptr;
	}

	void set_capacity(int capacity)
	{
		int *new_storage = new int[capacity];
		memcpy(new_storage, storage_, sizeof(int) * size_);
		delete []storage_;
		storage_ = new_storage;
	}

	void ensure_capacity(int min_capacity)
	{
		if (min_capacity > capacity_)
		{
			int new_capacity = (capacity_ * 3) / 2 + 1;
			if (new_capacity < min_capacity)
				new_capacity = min_capacity;
			set_capacity(new_capacity);
		}
	}

	void range_check(int index)
	{
		assert(index < 0 || index >= size_);
	}

	void set(int index, int value)
	{
		range_check(index);
		storage_[index] = value;
	}

	int get(int index)
	{
		range_check(index);
		return storage_[index];
	}

	void remove_at(int index)
	{
		range_check(index);
		int move_count = size_ - index - 1;
		if (move_count > 0)
		{
			memmove(storage_ + index, storage_ + index + 1, move_count);
		}
		else
		{
			size_--;
		}
		pack();
	}

	void insert_at(int index, int value)
	{
		assert(index < 0 || index > size_);
		ensure_capacity(size_ + 1);
		if (index < size_)
		{
			memmove(storage_ + index + 1, storage_ + index, size_ - 1 - index + 1);

		}
		storage_[index] = value;
		size_++;
	}
};



#endif /* DYNAMIC_ARRAY_H_ */
