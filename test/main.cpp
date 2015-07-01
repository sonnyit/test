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
  
  struct ListNode *a = new ListNode();
  cout << "list length: " << ListLength(a) << endl;

	return 0;
}



