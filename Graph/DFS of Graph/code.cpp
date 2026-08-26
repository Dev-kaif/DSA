#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution
{
    void dfsHelper(vector<vector<int>> &adj, int node,
                   vector<int> &res,
                   vector<bool> &visited)
    {

        res.push_back(node);
        visited[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(adj, neighbor, res, visited);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<int> res;
        vector<bool> visited(n, false);

        dfsHelper(adj, 0, res, visited);

        return res;
    }
};
