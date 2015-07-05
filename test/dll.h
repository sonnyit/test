#include <iostream>

struct DLLNode {
  int data;
  struct DLLNode *next;
  struct DLLNode *prev;
};

void DLLInsert(struct DLLNode **head, int data, int position)
{
  DLLNode *new_node = new DLLNode();
  new_node->data = data;
  if (position == 1)
  {
    new_node->next = *head;
    *head = new_node;
  }
  else
  {
    int k = 1;
    DLLNode *p = *head;
    while (k < position - 1 && p!=NULL)
    {
      k++;
      p = p->next;
    }
    if (p == NULL)
      return;
    new_node->next = p->next;
    new_node->prev = p;
    p->next->prev = new_node;
    p->next = new_node;
  }
}

void DLLPrint(DLLNode **head)
{
  DLLNode *p = *head;
  while (p != NULL)
  {
    std::cout << p->data << std::endl;
    p = p->next;
  }
}
