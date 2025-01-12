#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int start, const vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // Track visited nodes
    queue<int> q;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " "; // Process the current node

        // Visit all unvisited neighbors
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<int>> adjList(n);

    // Adding edges to the graph (undirected graph example)
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(4);
    adjList[3].push_back(5);

    // For undirected graph, add the reverse edges
    adjList[1].push_back(0);
    adjList[2].push_back(0);
    adjList[3].push_back(1);
    adjList[4].push_back(2);
    adjList[5].push_back(3);

    int startNode = 0;
    bfs(startNode, adjList);

    return 0;
}



