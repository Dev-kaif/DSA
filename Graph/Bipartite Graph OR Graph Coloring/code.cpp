#include <iostream>

using namespace std;

// https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
    bool res = true;

    void dfs(vector<vector<int>> &graph, int node, int c, vector<int> &colors)
    {

        // color the current node
        colors[node] = c;

        for (int neighbor : graph[node])
        {

            // If the connecting node has the same color as the current node, 
            // then the graph is not Bipartite.
            if (colors[neighbor] == c)
            {
                res = false;
            }
            else if (colors[neighbor] == -1)
            {

                // If the node is not colored yet, assign it the opposite color.
                // Red = 0, Blue = 1
                // If current color is Red: 1 - 0 = 1 -> Blue
                // If current color is Blue: 1 - 1 = 0 -> Red
                dfs(graph, neighbor, 1 - c, colors);
            }
        }
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int red = 0;
        int blue = 1;

        int n = graph.size();
        vector<int> colors(n, -1);

        for (int node = 0; node < n; node++)
        {

            // Start DFS for every unvisited node
            // because the graph can have multiple components.
            if (colors[node] == -1)
            {
                dfs(graph, node, red, colors);
            }
        }

        return res;
    }
};