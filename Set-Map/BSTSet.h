#ifndef SETMAP_BSTSET_H
#define SETMAP_BSTSET_H

#include "Set.h"
#include "BST.h"

template<class T>
class BSTSet : public Set<T> {
private:
	BST<T>* bst;
public:
	BSTSet() {
		bst = new BSTSet<T>();
	}

	int size() {
		return bst->size();
	}

	bool empty() {
		return bst->empty();
	}

	bool contain(T e) {
		return bst->contain(e);
	}

	void remove(T e) {
		return bst->remove(e);
	}

	void insert(T e) {
		return bst->insert(e);
	}
};

#endif  //SETMAP_BSTSET_H