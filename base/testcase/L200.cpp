#include <iostream>
#include <vector> // vector需要引用的头文件
#include "gtest/gtest.h"
using namespace std;

// 岛屿数量问题有多种接法，当前使用的是一种很僵化的图的解法主要是为了熟悉无向图的使用
// 所有的岛屿可以认为一个图, 找出岛屿的数目也就是找出连通图的数目
// 该方案实现基本沿用的《算法》一书中计算连通图数据的实现。
// 按照图问题的标准设计模式，将图的表示和实现分离开来
class Graph {
private:
    int v_; // vertex 顶点数
    int e_; // edge 边数目
    vector<vector<int>> adj_; // 邻接表
public:
    Graph(int v) { // 构造函数
        v_ = v;
        e_ = 0;
        adj_ = vector<vector<int>>(v);
    }
    int V() {
        return v_;
    }
    int E() {
        return e_;
    }
    void addEdge(int v, int w) {
        adj_[v].push_back(w);
        adj_[w].push_back(v);
        e_++;
    }
    vector<int> adj(int v) {
        return adj_[v];
    }
};

class CC {
private:
    vector<bool> marked_;
    vector<int> id_;
    int count_;
public:
    CC (Graph& g) {
        marked_ = vector<bool>(g.V(), false);
        id_ = vector<int>(g.V(), 0);
        count_ = 0;
        for (int s = 0; s < g.V(); s++) {
            if (!marked_[s]) {
                dfs(g, s);
                count_++;
            }
        }
    }
    bool connected(int v, int w) { // v和w连通吗
        return id_[v] == id_[w];
    }
    int id(int v) { // v所在的连通分量的标识符0 ~ count() - 1
        return id_[v];
    }
    int count() { // 连通分量数
        return count_;
    }
private:
    void dfs(Graph& g, int v) {
        marked_[v] = true;
        id_[v] = count_;
        for (int w = 0; w < g.adj(v).size();  w++) {
            int next = g.adj(v)[w];
            if (!marked_[next]) {
                dfs(g, next);
            }
        }
    }
    
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // 建图
        int row = grid.size();
        int col = grid[0].size();

        int v = 0;
        vector<vector<int>> vIndex(row, vector<int>(col, 0));
        int index = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != '0') {
                    v++;
                    vIndex[i][j] = index;
                    index++;
                }
            }
        }
        Graph graph(v);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                int v = vIndex[i][j];
                int w = 0;
                if (((i - 1) >= 0) && (grid[i - 1][j] == '1')) {
                    w = vIndex[i - 1][j];
                    graph.addEdge(v, w);
                }
                if (((i + 1) <= row - 1) && (grid[i + 1][j] == '1')) {
                    w = vIndex[i + 1][j];
                    graph.addEdge(v, w);
                }
                if (((j - 1) >= 0) && (grid[i][j - 1] == '1')) {
                    w = vIndex[i][j - 1];
                    graph.addEdge(v, w);
                }
                if (((j + 1) <= col - 1) && (grid[i][j + 1] == '1')) {
                    w = vIndex[i][j + 1];
                    graph.addEdge(v, w);
                }
            }
        }

        CC cc(graph);
        return cc.count();
    }
};

TEST(L127, CASE_002)
{
    class Solution s;
    char cGrid[4][5] = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };
    int row = sizeof(cGrid) / 5;
    int col = 5;

    vector<vector<char>> grid(row, vector<char>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            grid[i][j] = cGrid[i][j];
        }
    }
    int result = s.numIslands(grid);
    EXPECT_EQ(1, result);
}