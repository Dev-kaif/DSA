#include <iostream>

using namespace std;

// https://leetcode.com/problems/network-delay-time/

class Solution
{
    vector<vector<pair<int, int>>> create(int n, vector<vector<int>> &times)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> node : times)
        {  
            // make it 0 indexed 
            int src = node[0] - 1;
            int dest = node[1] - 1;
            int wt = node[2];

            adj[src].push_back({dest, wt});
        }
        return adj;
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph = create(n, times);
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        vector<int> dist(n, INT_MAX);

        // times is not 0 indexed , we need to make it 
        int src = k - 1;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            pair<int, int> current = pq.top();
            pq.pop();

            int d = current.first;
            int node = current.second;

            if (d > dist[node])
            {
                continue;
            }

            for (pair<int, int> edge : graph[node])
            {
                int neighbor = edge.first;
                int wt = edge.second;

                int newDist = d + wt;

                if (newDist < dist[neighbor])
                {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }

        int maxDist = 0;
        for (int wt : dist)
        {
            if (wt == INT_MAX)
            {
                return -1;
            }
            maxDist = max(maxDist, wt);
        }

        return maxDist;
    }
};