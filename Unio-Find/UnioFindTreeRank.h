#ifndef UNIOFIND_UNIOFINDTREERANK_H
#define UNIOFIND_UNIOFINDTREERANK_H

#include <iostream>

using namespace std;

class UnioFindTreeRank {
private:
	int* parent;
	int* rank;
	int count;
public:
	UnioFindTreeRank(int count) {
		parent = new int[count];
		rank = new int[count];
		this->count = count;
		for(int i =0; i < count; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	~UnioFindTreeRank() {
		delete[] parent;
		delete[] rank;
	}

	int find(int p) {
		while(p >= 0 && p < count)
			p = parent[p];
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
		
		if(rank[pRoot] < rank[qRoot]) {
			parent[pRoot] = qRoot;
		}
		else if(rank[pRoot] > rank[qRoot]) {
			parent[qRoot] = pRoot;
		}
		else {
			parent[pRoot] = qRoot;
			rank[qRoot] += 1;
		}
	}
};

#endif //UNIOFIND_UNIOFINDTREERANK_H
