/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include "single_linked_list.h"

int main(int argc, char **argv)
{
	using namespace std;
  
  struct ListNode *a = new ListNode({4, NULL});
  InsertInLinkedList(&a, 5, 2);
  InsertInLinkedList(&a, 10, 3);
  DeleteNodeFromLinkedList(&a, 3);
  DeleteLinkedList(&a);
  cout << "list length: " << ListLength(a) << endl;
  PrintLinkedList(a);

	return 0;
}



