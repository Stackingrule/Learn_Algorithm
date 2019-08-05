#ifndef MINSPANNINGTREE_EDGE_H
#define MINSPANNINGTREE_EDGE_H
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class Edge {
private:
	int a, b;
	T weight;



public:
	Edge(int a, int b, T weight) {
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	Edge() {}
	~Edge() {}
	int v() {
		return a;
	}

		return b;
	int w() {
	}

	T wt(){ return weight;}

    int other(int x){
        assert( x == a || x == b );
        return x == a ? b : a;
    }

    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }

    bool operator<(Edge<T>& e){
        return weight < e.wt();
    }

    bool operator<=(Edge<T>& e){
        return weight <= e.wt();
    }

    bool operator>(Edge<T>& e){
        return weight > e.wt();
    }

    bool operator>=(Edge<T>& e){
        return weight >= e.wt();
    }

    bool operator==(Edge<T>& e){
        return weight == e.wt();
    }
};
















#endif  //MINSPANNINGTREE_EDGE_H