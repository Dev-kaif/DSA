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

        vector<bool> visited(v, false);
        vector<int> cost(v, -1);

        int c = 0;

        // BFS starts from source.
        // The source is at distance 0.
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            // All nodes currently in the queue belong to the same level.
            // Therefore, they all have the same distance from the source.
            int size = q.size();

            while (size--)
            {
                int node = q.front();
                q.pop();

                if (!visited[node])
                {
                    visited[node] = true;

                    // Current BFS level represents the shortest
                    // distance from the source to this node.
                    cost[node] = c;

                    // Add all unvisited neighbors to the next BFS level.
                    for (int neighbor : graph[node])
                    {
                        if (!visited[neighbor])
                        {
                            q.push(neighbor);
                        }
                    }
                }
            }

            // Move to the next BFS level.
            // Each level represents one additional edge cost.
            c++;
        }

        // Returns -1 if destination was never reached.
        return cost[dest];
    }
};
