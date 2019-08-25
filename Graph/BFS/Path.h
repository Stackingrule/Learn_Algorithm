#ifndef PATH_H
#define PATH_H

#include <vector>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class Path {
private:
	Graph &G;
	int s;
	bool *visited;
	int *from;

	void dfs(int v) {
		visited[v] = true;

		typename Graph::adjIterator adj(G, v);
		for(int i = adj.begin(); !adj.end(); i = adj.next()) {
			if(!visited[i]) { 
				from[i] = v;
				dfs(i);
			}
		}
	}

public:

	Path(Graph &graph, int s) : G(graph) {

		assert(s >= 0 && s < G.Vertex());
		visited = new bool[G.Vertex()];
		from = new int[G.Vertex()];

		for(int i = 0; i < G.Vertex(); i++) {
			visited[i] = false;
			from[i] = -1;
		}

		this->s = s;
		dfs(s);
	}

	~Path() {
		delete[] visited;
		delete[] from;
	}

	bool hasPath(int w) {
		return visited[w];
	}

	void path(int w, vector<int> &vec) {
		stack<int> s;
		int p = w;
		while(p != -1) {
			s.push(p);
			p = from[p];
		}
		vec.clear();
		while(!s.empty()) {
			vec.push_back(s.top());
			s.pop();
		}
	}
 
	void show(int w) {
		assert( hasPath(w) );
		vector<int> vec;
		path(w, vec);
		for(int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if(i == vec.size() - 1)
				cout << endl;
			else
				cout << "->";
		}
	}

};

#endif  //PATH_H