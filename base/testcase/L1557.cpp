#include "gtest/gtest.h"
using namespace std;

// 只要找出入度为0的结点即可
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inVertex(n, false);
        for (int i = 0; i < edges.size(); i++) {
            inVertex[edges[i][1]] = true;
        }
        vector<int> outVertex;
        for (int i = 0; i < n; i++) {
            if (!inVertex[i]) {
                outVertex.push_back(i);
            }
        }

        return outVertex;
    }
};

TEST(L1557, CASE_001)
{
    vector<vector<int>> edges = {{0,1}, {0,2}, {2,5}, {3,4}, {4,2}};

    class Solution s;
    vector<int> outVertex = s.findSmallestSetOfVertices(6, edges);
    vector<int> expectedVertex = {0, 3};
    if (outVertex.size() == expectedVertex.size()) {
        for (int i = 0; i < outVertex.size(); i++) {
            EXPECT_EQ(expectedVertex[i], outVertex[i]);
        }
    } else{
        EXPECT_EQ(expectedVertex.size(), outVertex.size());
    }
}

TEST(L1557, CASE_002)
{
    vector<vector<int>> edges = {{0,1},{2,1},{3,1},{1,4},{2,4}};

    class Solution s;
    vector<int> outVertex = s.findSmallestSetOfVertices(5, edges);
    vector<int> expectedVertex = {0, 2, 3};
    if (outVertex.size() == expectedVertex.size()) {
        for (int i = 0; i < outVertex.size(); i++) {
            EXPECT_EQ(expectedVertex[i], outVertex[i]);
        }
    } else{
        EXPECT_EQ(expectedVertex.size(), outVertex.size());
    }
}
