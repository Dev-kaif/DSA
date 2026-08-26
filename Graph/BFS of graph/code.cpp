#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<int> res;
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return res;
    }
};
