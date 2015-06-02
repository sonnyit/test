/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include <string>
#include "hash_map.h"

int main(int argc, char **argv)
{
	using namespace std;
	HashMap<int, string, MyKeyHash> hash_map;
	hash_map.put(1, "con tau");
	hash_map.put(2, "trai cam");
	hash_map.put(3, "trai coc");
	string value;
	hash_map.get(3, value);
	cout << value << endl;
	return 0;
}



