#include <iostream>

struct ListNode
{
  int data;
  struct ListNode *next;
};

int ListLength(struct ListNode *head)
{
  struct ListNode *current = head;
  int count = 0;
  while (current)
  {
    count++;
    current = current->next;
  }
  return count;
}

void InsertInLinkedList(struct ListNode **head, int data, int position)
{
  struct ListNode *new_node = new ListNode();
  new_node->data = data;

  if (position == 1)
  {
    new_node->next = *head;
    *head = new_node;
  }
  else 
  {
    struct ListNode *p = *head;
    int k = 1;
    while(k < position-1 && p != NULL)
    {
      k++;
      p = p->next;
    }
    new_node->next = p->next;
    p->next = new_node;
  }
}

void DeleteNodeFromLinkedList(struct ListNode **head, int position)
{
  struct ListNode *p, *q;
  if (position == 1)
  {
    p = *head;
    *head = (*head)->next;
    delete p;
  }
  else
  {
    int k = 1;
    p = *head;
    while(k < position-1 && p!=NULL)
    {
      k++;
      p = p->next;
    }
    if (p==NULL) {
      std::cout << "null \n";
      return;
    }
    q = p->next;
    p->next = q->next;
    delete q;
  }
}

void DeleteLinkedList(struct ListNode **head)
{
  struct ListNode *p = *head;
  while (p != NULL)
  {
    *head = (*head)->next;
    delete p;
    p = *head;
  }
}

void PrintLinkedList(struct ListNode *head)
{
  using namespace std;
  struct ListNode *p = head;
  while (p != NULL)
  {
    cout << p->data << endl;
    p = p->next;
  }
}
