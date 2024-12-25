#include <iostream>
#include <vector>

using namespace std;

// Graph class
class Graph {
private:
    int vertices; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add an edge (directed or undirected)
    void addEdge(int src, int dest, bool isDirected = false) {
        adjList[src].push_back(dest);
        if (!isDirected) {
            adjList[dest].push_back(src);
        }
    }

    // Display the graph
    void displayGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5; // Example with 5 vertices
    Graph graph(vertices);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Display the graph
    cout << "Graph representation (Adjacency List):" << endl;
    graph.displayGraph();

    return 0;
}
