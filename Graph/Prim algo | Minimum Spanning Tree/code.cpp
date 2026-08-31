#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
    vector<vector<pair<int, int>>> create(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> edge : edges)
        {
            int src = edge[0];
            int des = edge[1];
            int wtt = edge[2];
            adj[src].push_back({des, wtt});
            adj[des].push_back({src, wtt});
        }
        return adj;
    }

public:
    int spanningTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> graph = create(n, edges);

        vector<bool> visited(n, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int sum = 0;

        pq.push({0, 0});
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            int wtt = p.first;
            int node = p.second;

            if (visited[node])
            {
                continue;
            };

            visited[node] = true;
            sum = sum + wtt;

            for (pair<int, int> edge : graph[node])
            {
                int neighbor = edge.first;
                int wt = edge.second;

                if (!visited[neighbor])
                    pq.push({wt, neighbor});
            }
        }

        return sum;
    }
};
