#include <iostream>

struct DLLNode {
  int data;
  struct DLLNode *next;
  struct DLLNode *prev;
};

void DLLInsert(struct DLLNode **head, int data, int position)
{
  DLLNode *new_node = new DLLNode({data, NULL, NULL});
  if (position == 1)
  {
    new_node->next = *head;
    *head = new_node;
  }
}

void DLLPrint(DLLNode **head)
{
  DLLNode *p = *head;
  while (p != NULL)
  {
    std::cout << *p << std::endl;
    p = p->next;
  }
}
