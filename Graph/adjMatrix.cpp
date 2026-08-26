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
    
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    for (pair<int, int> edge : edges)
    {
        int src = edge.first;
        int des = edge.second;

        adjMatrix[src][des] = 1;
        adjMatrix[des][src] = 1; // Remove this for directed graph
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}