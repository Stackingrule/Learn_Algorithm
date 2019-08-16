#ifndef SETMAP_LINKEDLISTSET_H
#define SETMAP_LINKEDLISTSET_H

#include "LinkedListSet.h"
template<class T>
class LinkedListSet : public Set<T> {
private:
	LinkedList<T>* list;

public:
	LinkedListSet() {
		list = new LinkedList<T>();
	}

	int size() {
		return list->size();
	}

	bool empty() {
		return list->empty();
	}

	bool contain(T e) {
		return list->contain(e);
	}

	void insert(T e) {
		if(!contain(e)) {
			list->insertAsFirst(e);
		}
	}

	void remove(T e) {
		list->removeElem(e);
	}

};

#endif  //SETMAP_LINKEDLISTSET_H