#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution
{
    bool cycle = false;

    vector<vector<int>> createList(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);

        for (auto edge : edges)
        {
            int src = edge[0];
            int des = edge[1];

            adjList[src].push_back(des);
            adjList[des].push_back(src);
        }

        return adjList;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int parent)
    {
        if (cycle)
            return;

        visited[node] = true;

        for (int curr : graph[node])
        {
            if (visited[curr] && curr != parent)
            {
                cycle = true;
            }
            else if (!visited[curr])
            {
                dfs(graph, visited, curr, node);
            }
        }

        return;
    }

public:
    bool isCycle(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph = createList(v, edges);

        vector<bool> visited(v, false);

        for (int node = 0; node < v; node++)
        {
            if (!visited[node])
                dfs(graph, visited, node, -1);
        }

        return cycle;
    }
};
