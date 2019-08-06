#ifndef AVL_AVLMAP_H
#define AVL_AVLMAP_H

#include "Map.h"
#include "AVLTree.h"

template<typename Key, typename Value>
class AVLMap : Map<Key, Value> {
private:
	AVLTree<Key, Value>* avlTree;


public:
	AVLMap() {
		avlTree = new AVLTree<Key, Value>;
	}

	~AVLMap() {}

	int size() {
		return avlTree->size();
	}

	bool empty() {
		return avlTree->empty();
	}

	void insert(Key key, Value value) {
		avlTree->insert(key, value);
	} 

	bool contain(Key key) {
		return avlTree->contain(key);
	}

	Value* getValue(Key key) {
		return avlTree->getValue(key);

	}

	Value* remove(Key key) {
		return avlTree->remove(key);
	}

	void set(Key key, Value value) {
		avlTree->set(key, value);
	}

};

#endif  //AVL_AVLMAP_H