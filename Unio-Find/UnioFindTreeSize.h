#ifndef UNIOFIND_UNIOFINDTREESIZE_H
#define UNIOFIND_UNIOFINDTREESIZE_H

#include <iostream>
using namespace std;

class UnioFindTreeSize {
private:
	int* parent;
	int* _size;
	int count;
public:
	UnioFindTreeSize(int count) {
		parent = new int[count];
		this->count = count;
		for(int i = 0; i < count; i++) {
			parent[i]  = i;
		    _size[i] = i;
		}
	}

	~UnioFindTreeSize() {
		delete[] parent;
		delete[] _size;
	}

	int size(){
        return count;
    }

    bool isConnected( int p , int q ){
        return find(p) == find(q);
    }

    int find(int p) {
        while( p != parent[p] )
            p = parent[p];
        return p;
    }

    void unionElements(int p, int q){

		int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        if( _size[pRoot] < _size[qRoot] ){
            parent[pRoot] = qRoot;
            _size[qRoot] += _size[pRoot];
        }
        else{   // sz[pRoot] >= sz[qRoot]
            parent[qRoot] = pRoot;
            _size[pRoot] += _size[qRoot];
        }
    }
};

#endif //UNIOFIND_UNIOFINDTREESIZE_H
