/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include "dynamic_array.h"

int main(int argc, char **argv)
{
	using namespace std;
	DynamicArray darr(10);
	darr.set(0, 1);
	darr.set(1, 2);
	cout << darr.get(1) << endl;
	return 0;
}



