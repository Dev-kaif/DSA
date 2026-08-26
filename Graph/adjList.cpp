#include <iostream>

using namespace std;

int main()
{

    // Vertices
    vector<int> vertices = {0, 1, 2, 3, 4};

    // Edges: {source, destination}
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {3, 4}};

    int n = vertices.size();

    vector<vector<int>> adjList(n);

    for (pair<int, int> edge : edges)
    {
        int src = edge.first;
        int des = edge.second;

        adjList[src].push_back(des);
        adjList[des].push_back(src); // Remove this for directed graph
    }

    // Print adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";

        for (int neighbor : adjList[i])
        {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    return 0;
}