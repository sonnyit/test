/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include <cstring>
#include <stdint.h>

template <typename K>
struct Add
{
	K operator()(K a)
	{
		return a;
	}
};

int main(int argc, char **argv)
{
	using namespace std;
	Add<int> add;
	int a = add(5);
	cout << a << endl;

	return 0;
}



