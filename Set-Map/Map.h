#ifndef SETMAP_MAP_H
#define SETMAP_MAP_H

template<typename Key, typename Value>
class Map
{
public:
	int size();

	bool empty();

	bool contain(Key key);

	void insert(Key key, Value value);

	void set(Key key, Value value);

	Value get(Key key);
	
	Value remove(Key key);

};

#endif  //SETMAP_MAP_H