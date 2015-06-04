#include "linked_list.h"

template <typename E>
SLinkedList<E>::SLinkedList() : head(nullptr) {}

template <typename E>
SLinkedList<E>::empty() const
{
  return head == nullptr;
}

template <typename E>
const E& SLinkedList<E>::front() const
{
  return head->element;
}

template <typename E>
SLinkedList::~SLinkedList()
{
  while (!empty())
  {
    remove_front();
  }
}

template <typename E>
void SLinkedList<E>::add_front(const E& e)
{
  SNode<E> *node = new SNode<E>;
  node->element = e;
  node->next_ = head;
  head = node;
}

template <typename E>
void SLinkedList<E>::remove_front()
{
  SNode<E> *node = head;
  head = head->next_;
  delete node;
  node = nullptr;
}
