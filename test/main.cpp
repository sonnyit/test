/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */

#include "dll.h"
#include <iostream>
#include <memory>

int main(int argc, char **argv)
{
	using namespace std;
  DLLNode *a = new DLLNode({9, NULL, NULL});
  DLLInsert(&a, 2, 1);
  DLLInsert(&a, 5, 2);

  DLLPrint(&a);
	return 0;
}



