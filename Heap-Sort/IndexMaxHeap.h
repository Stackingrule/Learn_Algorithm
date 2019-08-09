#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class IndexMaxHeap{
private:
	T* data;
	int* index;
	int count;
	int capacity;

	void shiftUp(int k) {
		while(k > 1 && data[index[k/2]] < data[index[k]]) {
			swap(index[k/2], index[k]);
			k /= 2;
		}
	}

	void shiftDown(int k) {
		while(2*k <= count) {
			int j = 2*k;
			if( j + 1 <= count && data[index[j+1]] > data[index[j]])
				j ++;
		    if(data[index[k]] >= data[index[j]] )
			    break;
	        swap(index[k], index[j] );
	        k = j;
		}
	}

public:
	IndexMaxHeap(int capacity) { 
		data = new T[capacity + 1]; 
		index = new int[capacity+1];
		count = 0; 
		this->capacity = capacity;
	}

	IndexMaxHeap(T arr[], int n){
        data = new T[n+1];
        capacity = n;

        for( int i = 0 ; i < n ; i++ )
            data[i+1] = arr[i];
        count = n;

        for( int i = count/2 ; i >= 1 ; i-- )
            shiftDown(i);
    }

	~IndexMaxHeap() { 
		delete[] data; 
		delete[] index;
	}

	int size() {
		return count;
	}

	bool empty() {
		return count == 0;
	}

	void insert(int i, T e) {
		assert(count + 1 <= capacity);
		assert(i + 1 >= 1);
		i += 1;
		data[i] = e;
		index[count+1] = i;
		count++;
		shiftUp(count);
	}

	T delMax() {
		assert(count > 0);
		T ret = data[index[1]];
		swap(index[1], index[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	int delMaxIndex() {
		assert(count > 0);
		int ret = index[1] - 1;
		swap(index[1], index[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	T getElem(int i) {
		return data[i+1];
	}

	void change(int i, T e) {
		i += 1;
		data[i] = e;

		for(int j =1; j <= count; j++) {
			if(index[j] == i) {
				shiftUp(j);
				shiftDown(j);
				return;
			}
		}
	} 

	T getMax(){
        assert( count > 0 );
        return data[index[1]];
    }


};


#endif  //HEAP_H