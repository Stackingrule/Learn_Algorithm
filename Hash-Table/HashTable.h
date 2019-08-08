#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include "RBTree.h"

template<typename Key, typename Value>
class HashTable {
private:
	int M;
	int _size;
	int upperTol = 10;
	int lowerTol = 2;
	int capacity = 7;
	RBTree<Key, Value>* hashTable[];

	int hash(Key key) {
		return (hashCode(key) & 0x7fffffff) % M;
	}

	int hashCode(Key key) {
		std::hash<Key> hash_key;
		return hash_key(key);
	}

	//void resize(int M) {}

public:

	HashTable(int M) {
		this->M = M;
		_size = 0;
		*hashTable = new RBTree<Key, Value>[M] {};
		for(int i = 0; i < M; i++) {
			hashTable[i] = new RBTree<Key, Value>();
		}
	}

	HashTable() {
        this->M = 97;
        _size = 0;
        *hashTable = new RBTree<Key, Value>[M] {};
        for (int i = 0; i < M; ++i) {
            hashTable[i] = new RBTree<Key, Value>();
        }
    }

	int size() {
		return _size;
	}

	bool contain(Key key) {
		return hashTable[hash(key)]->contain(key);
	}

	void insert(Key key, Value value) {
		RBTree<Key, Value>* rbTree = hashTable[hash(key)];
		if(rbTree->contain(key)) {
			rbTree->set(key,value);
		}
		else {
			rbTree->insert(key, value);
			_size++;
		}
	} 

	void set(Key key, Value value) {
		RBTree<Key, Value>* rbTree = hashTable[hash(key)];
		if(!rbTree->contain(key)) {
			std::cout << key << " doesn't exist";
		}
		rbTree->set(key, value);
	}

	//Value remove(Key key) {}

	Value getValue(Key key) {
		return hashTable[hash(key)]->getValue(key);
	}


};

#endif  //HASHTABLE_HASHTABLE_H