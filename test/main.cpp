/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include <cstring>
#include <stdint.h>

struct Add
{
	int operator()(int a)
	{
		return 5;
	}
};

int main(int argc, char **argv)
{
	using namespace std;
	Add add;
	int a = add(5);
	cout << a << endl;

	return 0;
}



