#ifndef UNIOFIND_UNIOFINDTREESIZE_H
#define UNIOFIND_UNIOFINDTREESIZE_H

class UnioFindTreePath {
private:
	int* parent;
	int* rank;
	int count;

public:
	UnioFindTreePath(int count) {
		parent = new int[count];
		rank = new int[count];
		this->count = count;
		for(int i =0; i < count; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	~UnioFindTreePath() {
		delete[] parent;
		delete[] rank;
	}

	int find(int p) {
		while( p != parent[p] ){
                parent[p] = parent[parent[p]];
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

#endif //UNIOFIND_UNIOFINDTREESIZE_H
