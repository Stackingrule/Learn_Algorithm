#ifndef AVL_MAP_H
#define AVL_MAP_H

template<typename Key, typename Value>
class Map {
	void insert(Key key, Value value);
	Value remove(Key key);
	bool contain(Key key);
	Value get(Key key);
	void set(Key key, Value value);
    int size();
    bool empty();
};

#endif  //AVL_MAP_H