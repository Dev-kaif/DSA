#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
public:
    vector<int> bellmanFord(int n, vector<vector<int>> &edges, int src)
    {
        auto MAX = 1e8;
        vector<int> dist(n, INT_MAX);

        // Distance from source to itself is 0
        dist[src] = 0;

        // Relax every edge n - 1 times
        for (int pass = 0; pass < n - 1; pass++)
        {

            for (vector<int> edge : edges)
            {

                int s = edge[0];
                int d = edge[1];
                int wt = edge[2];

                // If source is reachable and this edge
                // gives us a shorter path, update the distance.
                if (dist[s] != INT_MAX && dist[d] > dist[s] + wt)
                {
                    dist[d] = dist[s] + wt;
                }
            }
        }

        // One more relaxation:
        // if we can still improve a distance,
        // a negative weight cycle exists.
        for (vector<int> edge : edges)
        {

            int s = edge[0];
            int d = edge[1];
            int wt = edge[2];

            if (dist[s] != INT_MAX && dist[d] > dist[s] + wt)
            {
                return {-1};
            }
        }

        return dist;
    }
};
