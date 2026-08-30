#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution
{
    vector<vector<int>> create(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);

        for (vector<int> node : edges)
        {
            int src = node[0];
            int des = node[1];

            adj[src].push_back(des);
            adj[des].push_back(src);
        }

        return adj;
    }

public:
    int shortestPath(int v, vector<vector<int>> &edges, int src, int dest)
    {

        vector<vector<int>> graph = create(v, edges);

        vector<int> cost(v, -1);

        cost[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node])
            {
                if (cost[neighbor] == -1)
                {
                    cost[neighbor] = cost[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return cost[dest];
    }
};
