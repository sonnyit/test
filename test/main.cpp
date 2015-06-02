/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include <string>
#include "hash_map.h"

struct MyKeyHash {
	unsigned long operator()(const int &k) const
	{
		return k % 10;
	}
};

int main(int argc, char **argv)
{
	using namespace std;
	HashMap<int, string> hash_map;

	return 0;
}



