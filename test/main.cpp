/*
 * main.cpp
 *
 *  Created on: May 28, 2015
 *      Author: MinhNH13
 */
#include <iostream>
#include <memory>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void sort012(int *a, int size)
{
  int lo = 0;
  int mid = 0;
  int hi = size-1;

  while (mid <= hi)
  {
    switch (*(a+mid))
    {
      case 0:
      {
        swap(a+lo, a+mid);
        lo++;
        mid++;
      }
      break;
      case 1:
      {
        mid++;
      }
      break;
      case 2:
      {
        swap(a+mid, a+hi);
        hi--;
      }
      break;
    }
  }
}

int main(int argc, char **argv)
{
	using namespace std;

  int a[] = {1, 2, 0, 0, 2, 2, 1, 1, 0, 1};
  sort012(a, 10);
  for (auto v : a)
    cout << v << endl;

	return 0;
}



