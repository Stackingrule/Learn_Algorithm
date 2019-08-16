#ifndef SETMAP_LINKEDLISTMAP_H
#define SETMAP_LINKEDLISTMAP_H

#include <iostream>
#include "Map.h"

template<typename Key, typename Value>
class Node {
public:
	Key key;
	Value value;
	Node<Key, Value>* next;

	Node(Key key, Value value, Node<Key, Value>* next) : key(key), value(value), next(next) {}
	Node() : key(), value(), next(nullptr) {}

};

template<typename Key, typename Value>
class LinkedListMap : public Map<Key, Value> {
private:
	Node<Key, Value>* dummyHead;
	int _size;

public:
	LinkedListMap() {
		dummyHead = new Node<Key, Value>();
		_size = 0;
	}

	int size() {
		return _size;
	}

	bool empty() {
		return _size == 0;
	}

	bool contain(Key key) {}

	Value* get(Key key) {}

	void insert(Key key, Value value) {}

	void set(Key key, Value newValue) {}

	Value* remove(Key key) {}

};

#endif  //SETMAP_LINKEDLISTMAP_H