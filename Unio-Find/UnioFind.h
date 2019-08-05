#ifndef UNIO_FIND_H
#define UNIO_FIND_H

#include <iostream>

using namespace std;

template<typename T>
class UnioFind {
private:
	int* id;
	int count;
public:
	UnioFind(int n) {
		count = n;
		id = new int[n];
		for(int i=0; i < n; i++){
			id[i] = i;
		}
	}
	~UnioFind() {
		delete[] id;
	}

	int find(int p) {
		return id[p];
	}

	bool isConnected(int p, int q) {
		return id[p] == id[q];
	}

	void unioElement(int p, int q) {
		int pID = find(p);
		int qID = find(q);

		if(pID == qID) return;

		for(int i=0; i < count; i++) {
			if(id[i] == pID)
				id[i] = qID;
		}
	}
};





#endif  //UNIO_FIND_H