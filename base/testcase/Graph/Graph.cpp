#include <iostream>
using namespace std;

class Graph {
private:
    int v; // 顶点数目
    int e; // 边的数目
    vector<vector<int>> adj; // 临接表
public:
    Graph(int v) {
        v = v;
        e = 0;
        adj = new vector<vector<int>>(v);
    }

    int V() {
        return v;
    }
    int E() {
        return E;
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
        e++;
    }
    vector<int> adj(int v) {
        return adj[v];
    }
}