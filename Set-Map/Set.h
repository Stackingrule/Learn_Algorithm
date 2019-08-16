#ifndef SETMAP_SET_H
#define SETMAP_SET_H

template<class T>
class Set {
	void insert(T e);
	void remove(T e);
	bool contain(T e);
	int size();
	bool empty();
};

#endif  //SETMAP_SET_H