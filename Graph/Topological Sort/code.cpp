#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution
{
    vector<vector<int>> createList(int n, vector<vector<int>> &edges, vector<int> &inDegree)
    {
        vector<vector<int>> adjList(n);

        for (auto &edge : edges)
        {
            int src = edge[0];
            int dest = edge[1];

            adjList[src].push_back(dest);
            inDegree[dest]++;
        }

        return adjList;
    }

public:
    vector<int> topoSort(int v, vector<vector<int>> &edges)
    {

        vector<int> inDegree(v, 0);
        vector<vector<int>> graph = createList(v, edges, inDegree);

        vector<int> res;
        queue<int> q;

        // Start with nodes that have no dependencies
        for (int node = 0; node < v; node++)
        {
            if (inDegree[node] == 0)
            {
                q.push(node);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            res.push_back(node);

            // Process nodes that depend on the current node
            for (int neighbor : graph[node])
            {
                inDegree[neighbor]--;

                // Execute only when all dependencies are completed
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return res;
    }
};
