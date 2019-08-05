#ifndef UNIOFIND_TREE_H
#define UNIOFIND_TREE_H

#include <iostream>
using namespace std;

template<typename T>
class UnioFindTree {
private:
	int* parent;
	int count;
public:
	UnioFindTree(int count) {
		parent = new int [count];
		this->count = count;
		for(int i = 0; i < count; i++)
			parent[i] = i;
	}

	~UnioFindTree() {
		delete[] parent;
	}

	int find(int p) {
		while(p != parent[p]) {
			p = parent[p];
		} 
		return p;
	}

	bool isConnected(int p, int q) {
		return find(p) == find(q);
	}

	void unioElement(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if(pRoot == qRoot)
			return;
		parent[pRoot] = qRoot;
	}
};

#endif  //UNIOFIND_TREE_H