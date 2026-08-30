#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
    vector<vector<pair<int, int>>> create(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adjList(n);

        for (vector<int> node : edges)
        {
            int src = node[0];
            int des = node[1];
            int wt = node[2];

            adjList[src].push_back({des, wt});
            adjList[des].push_back({src, wt});
        }

        return adjList;
    }

public:
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> graph = create(v, edges);

        // pair = {distance, node}

        // Min heap:
        // The node with the smallest distance will always be at the top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // dist[i] = shortest distance from src to node i
        vector<int> dist(v, INT_MAX);

        // Distance from source to itself is 0
        dist[src] = 0;

        // Start with the source
        // {distance, node}
        pq.push({0, src});

        while (!pq.empty())
        {
            // Get the pair from the top of the min heap
            pair<int, int> current = pq.top();
            pq.pop();

            // Break the pair into distance and node
            int d = current.first;
            int node = current.second;

            // This is an outdated entry.
            // We already found a shorter distance for this node.
            if (d > dist[node])
            {
                continue;
            }

            // Check all neighbors of the current node
            for (pair<int, int> edge : graph[node])
            {
                // edge = {neighbor, weight}
                int neighbor = edge.first;
                int wt = edge.second;

                // Distance to neighbor if we travel through current node
                int newDist = d + wt;

                // If this path is shorter, update the distance
                if (newDist < dist[neighbor])
                {
                    dist[neighbor] = newDist;

                    // Add the updated distance to the min heap
                    pq.push({newDist, neighbor});
                }
            }
        }

        return dist;
    }
};
