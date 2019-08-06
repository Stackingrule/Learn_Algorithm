#ifndef AVL_AVLSET_H
#define AVL_AVLSET_H

#include "Set.h"
#include "AVLTree.h"

template<class T>
class AVLSet : public Set<T> {
private:
	AVLTree<T, T>* avlTree;

public:
	AVLSet() {
		avlTree = new AVLTree<T, T>();
	}

	int size() {
		return avlTree->size();
	}

	bool empty() {
		return avlTree->empty();
	}

	bool contain(T e) {
		return avlTree->contain(e);
	}

	void insert(T e) {
		avlTree->insert(e, e);
	}

	void remove(T e) {
		avlTree->remove(e);
	}




};
#endif  //AVL_AVLSET_H