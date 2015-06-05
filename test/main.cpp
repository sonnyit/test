/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include "linked_list.h"

int main(int argc, char **argv)
{
	using namespace std;
	SLinkedList<int> linked;
	linked.add_front(5);
	linked.add_front(8);
	cout << linked.front() << endl;
	linked.remove_front();
	cout << linked.front() << endl;
	return 0;
}



