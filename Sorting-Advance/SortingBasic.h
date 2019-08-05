#ifndef SORTING_BASIC_H
#define SORTING_BASIC_H

#include <iostream>
#include <assert.h>
using namespace std;

template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}


template<typename T>
void insertionSort(T arr[], int n) {
	for(int i=1; i < n; i++) {
		T e = arr[i];
		int j;
		for(j = i; j > 0 && arr[j - 1] > e; j--) 
			arr[j] = arr[j - 1];
		
		arr[j] = e;
	}
}


#endif  //SORTING_BASIC_H

