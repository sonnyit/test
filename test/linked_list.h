#ifndef _LINKED_LIST_H_
#define _LINKED_LISH_H_
#include <iostream>

template<typename E>
class SNode {
public:
	SNode(const E &data) : data_(data), next_(nullptr) {}
	virtual ~SNode() {}

	void set_data(const E &data) {
		data_ = data;
	}

	const E& get_data() const {
		return data_;
	}

	SNode<E> *get_next() const {
		return next_;
	}

	void set_next(SNode<E> *node)
	{
		next_ = node;
	}
private:
	E data_;
	SNode<E> *next_;
};

template<typename E>
class SLinkedList {
public:
	SLinkedList() :
			head_(nullptr) {
	}

	virtual ~SLinkedList() {
		while (!empty())
		{
			remove_front();
		}
	}

	bool empty() const
	{
		return head_ == nullptr;
	}

	E front() const
	{
		return head_->get_data();
	}

	void add_front(const E& e)
	{
		SNode<E> *node = new SNode<E>(e);
		node->set_next(head_);
		head_ = node;
	}

	void remove_front()
	{
		SNode<E> *new_head = head_->get_next();
		delete head_;
		head_ = new_head;
	}

private:
	SNode<E> *head_;
};

#endif /* _LINKED_LISH_H_ */
