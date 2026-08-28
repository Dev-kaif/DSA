#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

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
        }

        return adjList;
    }

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &path, int node)
    {
        if (cycle)
            return;

        visited[node] = true;
        path[node] = true;

        for (int curr : graph[node])
        {
            if (visited[curr] && path[curr])
            {
                cycle = true;
            }
            else if (!visited[curr])
            {
                dfs(graph, visited, path, curr);
            }
        }

        path[node] = false;
    }

public:
    bool isCyclic(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph = createList(v, edges);
        vector<bool> visited(v, false);
        vector<bool> path(v, false);

        for (int node = 0; node < v; node++)
        {
            if (!visited[node])
            {
                dfs(graph, visited, path, node);
            }
        }

        return cycle;
    }
};
