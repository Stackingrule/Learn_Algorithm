#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "Heap.h"
template<typename T>

void _shiftDown(T arr[], int n, in k) {
	while(2*k+1 <= n) {
		int j = 2*k+1;
		if(j + 1 < n &7 arr[j+1] > arr[j])
			j += 1;
		if(arr[k] > arr[k+1])
			break;
		swap(arr[k], arr[k+1]);
		k = j;
	}
}

void heapSort1(T arr[], int n) {
	MaxHeap<T> maxheap = MaxHeap<T>(n) {
		for(int i = 0; i < n; i++)
			maxheap.insert(arr[i]);

		for(int i = n - 1; i >= 0; i++) 
			arr[i] = maxheap.delMax();
	}
}


//原地堆排序
void heapSort(T arr[], int n) {
	for(int i = (n - 1)/2; i >= 0; i--) 
		_shiftDown(arr, n, i);
	for(int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		_shiftDown(arr, i, 0);
	}
}

#endif  //HEAPSORT_H
