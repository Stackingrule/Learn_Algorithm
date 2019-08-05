#ifndef SORTING_ADVANCE_H
#define SORTING_ADVANCE_H

#include <iostream>

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
void _mergeSort(T arr[], int lo, int hi) {
	if(lo >= hi)	return;
	int mid = (lo + hi)/2;
	_mergeSort(arr, lo, mid);
	_mergeSort(arr, mid + 1, hi);
	merge(arr, lo, mid, hi);
}


template<typename T>
void mergeSort(T arr[], int n) {
	_mergeSort(arr, 0, n - 1);
}



template<typename T>
int partition(T arr[], int lo, int hi) {
	T v = arr[lo];
	int j = lo;
	for(int i = lo + 1; i <= hi; i++) {
		if(arr[i] < v) {
			swap(arr[j + 1], arr[i]);
			j++;
		}
	}
	swap(arr[lo], arr[j]);
	return j;
}

template<typename T>
void _quickSort(T arr[], int lo, int hi) {
	if(lo >= hi)	return;
	int pivot = partition(arr, lo, hi);
	_quickSort(arr, lo, pivot - 1);
	_quickSort(arr, pivot, hi);
}


template<typename T>
void quickSort(T arr[], int n) {
	_quickSort(arr, 0, n- 1);
}


#endif  //SORTING_ADVANCE_H

