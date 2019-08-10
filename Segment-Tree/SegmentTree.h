#ifndef SEGMENT_TREE_SEGMENTTREE_H
#define SEGMENT_TREE_SEGMENTTREE_H

#include <cassert>
#include <functional>

template<class T>
class SegmentTree
{
private:
	int* data;
	int* tree;
	int _size;
	std::function<T(T, T)> function;

	int leftChild(int index) {
		return index * 2;
	}

	int rightChild(int index) {
		return index * 2 + 1;
	}

	void buildSegmentTree(int treeIndex, int l, int r) {
		if(l == r) {
			tree[treeIndex] = data[l];
			return;
		}

		int leftChildIndex = leftChild(treeIndex);
		int rightChildIndex = rightChild(treeIndex);

		int mid = l + (r - l)/2;

		buildSegmentTree(leftChildIndex, l, mid);
		buildSegmentTree(rightChildIndex, mid + 1, r);

		tree[treeIndex] = tree[leftChildIndex] + tree[rightChildIndex];	//根据业务确定
	}

	T query(int treeIndex, int l, int r, int queryL, int queryR) {
		if(l == queryL && r == queryR)
			return tree[treeIndex];
		int mid = l + (r - l)/2;
		int leftChildIndex = leftChild(treeIndex);
		int rightChildIndex = rightChild(treeIndex);

		if(queryL > mid + 1) 
			return query(rightChildIndex, mid + 1, r, queryL, queryR);
		else if(queryR <= mid) 
			return query(leftChildIndex, l, mid, queryL, queryR);

		T leftResult = query(leftChildIndex, l, mid, queryL, mid);
		T rightResult = query(rightChildIndex, mid + 1, r, mid + 1, queryR);
		return function(leftResult, rightResult);
	}

public:
	SegmentTree(T arr[], int n, std::function<T(T, T)> function) {
		this->function = function;
		data = new T[n];
		for(int i = 0; i < n; i++) {
			data[i] = arr[i];
		}
		tree = new T[n * 4];
		_size = n;
		buildSegmentTree(0, 0, _size - 1);
	}

	~SegmentTree() {}

	int size() {
		return _size;
	}

	T get(int index) {
		return data[index];
	}

	T query(int queryL, int queryR) {
		assert(queryL >= 0 && queryL < size && queryR >= 0 && queryR < size && queryL <= queryR);
		return query(0, _size - 1, queryL, queryR);
	}
	
};

#endif  //SEGMENT_TREE_SEGMENTTREE_H