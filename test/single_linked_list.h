
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

void InsertInLinkedList(struct ListNode *head, int data, int position)
{
  struct ListNode *new_node = new ListNode();
  new_node->data = data;

  if (position == 1)
  {

  }
}
