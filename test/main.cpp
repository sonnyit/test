/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include <cstring>
#include <stdint.h>

int add(int a, int b) {
	return a + b;
}

int main(int argc, char **argv)
{
	using namespace std;
	char str[] = "this is a test sentence.";
	if (strncmp(&str[5], "is", 2) == 0)
		cout << "same" << endl;
	else
		cout << "not same" << endl;


	return 0;
}



