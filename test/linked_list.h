#ifndef _LINKED_LIST_H_
#define _LINKED_LISH_H_

template <typename E>
class SNode
{
  private:
    E element;
    SNode<E> *next_;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList
{
  public:
    SLinkedList();
    virtual ~SLinkedList();
    bool empty() const;
    const E& front() const;
    void add_front(const E& e);
    void remove_front();

  private:
    SNode<E> *head;
};

#endif /* _LINKED_LISH_H_ */
