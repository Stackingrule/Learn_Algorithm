#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>

using namespace std;

template<typename Graph>
class ShortestPath {
private:
	Graph &G;
	int s;
	int *from;
	bool *visited;
	int *ord;

public:
	ShortestPath(Graph &graph, int s) : G(graph) {
		assert(s >= 0 && s < graph.Vertex());

		visited = new bool[graph.Vertex()];
		from = new int[graph.Vertex()];
		ord = new int[graph.Vertex()];
		for(int i =0; i < graph.Vertex(); i++) {
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}

		this->s = s;

		queue<int> q;

		//无向图的最短路径算法
		q.push(s);
		visited[s] = true;
		ord[s] = 0;
		while(!q.empty()) {
			int v = q.front();
			q.pop();
			typename Graph::adjIterator adj(G, v);
			for(int i = adj.begin(); !adj.end(); adj.next()) {
				if(!visited[i]) {
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
			}
		}
	}

	~ShortestPath() {
		delete[] visited;
		delete[] from;
		delete[] ord;
	}

	// 查询从s点到w点是否有路径
	bool hasPath(int w){
	    assert( w >= 0 && w < G.Vertex() );
	    return visited[w];
	}

	// 查询从s点到w点的路径, 存放在vec中
	void path(int w, vector<int> &vec){

	    assert( w >= 0 && w < G.Vertex() );

	    stack<int> s;
	    // 通过from数组逆向查找到从s到w的路径, 存放到栈中
	    int p = w;
	    while( p != -1 ){
	        s.push(p);
	        p = from[p];
	    }

	    // 从栈中依次取出元素, 获得顺序的从s到w的路径
	    vec.clear();
	    while( !s.empty() ){
	        vec.push_back( s.top() );
	        s.pop();
	    }
	}

	// 打印出从s点到w点的路径
	void showPath(int w){

	    assert( w >= 0 && w < G.Vertex() );

	    vector<int> vec;
	    path(w, vec);
	    for( int i = 0 ; i < vec.size() ; i ++ ){
	        cout<<vec[i];
	        if( i == vec.size()-1 )
	            cout<<endl;
	        else
	            cout<<" -> ";
	    }
	}

	// 查看从s点到w点的最短路径长度
	int length(int w){
	    assert( w >= 0 && w < G.Vertex() );
	    return ord[w];
	}

};

#endif  //BFS_H