#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H
#include <iostream>
#include <ctime>
#include <assert>

using namespace std;

namespace SortTestHelper{
	int* generateRandomArray(int n, int rangeL, int rangeR) {
		assert(rangeL < rangeR);
		int *arr = new int[n];
		srand(time(nullptr));
		for(int i=0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1);
		}
		return arr;
	}
}



#endif  //SORTTESTHELPER_H
