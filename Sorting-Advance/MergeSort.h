#ifndef SORTING_ADVANCE_H
#define SORTING_ADVANCE_H

#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>  //arr[lo, hi)
void merge(T arr[], int lo, int mid, int hi) {
	T aux[hi - lo + 1];
	for(int i = lo; i <= hi; i++){
		aux[i - lo] = arr[i];
	}
	int i = lo, j = mid + 1;
	for(int k = lo; k <= hi; k++) {
		if(i > mid) {
			arr[k] = aux[j - lo];
		}
		else if(j > hi) {
			arr[k] = aux[i - k];
		}
		else if(aux[i - lo] < aux[j - lo]) {
			arr[k] = aux[i - lo];
			i++;
		}
		else {
			arr[i - lo] = aux[j - lo];
			j++;
		}
	}
}


template<typename T>
void mergeSort(T arr[], int lo, int hi) {
	if(lo >= hi)	return;
	int mid = ()
}




#endif  //SORTING_ADVANCE_H