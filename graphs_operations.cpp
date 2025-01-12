#include <iostream>
#include <vector>
#include <algorithm>

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

    // Add a new vertex
    void addVertex() {
        adjList.push_back({});
        vertices++;
        cout << "Vertex " << vertices - 1 << " added." << endl;
    }

    // Update a vertex name (just renaming here)
    void updateVertex(int oldID, int newID) {
        if (oldID < 0 || oldID >= vertices) {
            cout << "Invalid vertex ID." << endl;
            return;
        }
        cout << "Vertex " << oldID << " updated to " << newID << "." << endl;
    }

    // Delete a vertex
    void deleteVertex(int v) {
        if (v < 0 || v >= vertices) {
            cout << "Invalid vertex ID." << endl;
            return;
        }

        // Remove all edges connected to this vertex
        adjList.erase(adjList.begin()+v);
        for (auto &neighbors : adjList) {
            neighbors.erase(remove(neighbors.begin(), neighbors.end(),v), neighbors.end());
        }
        vertices--;

        cout << "Vertex " << v << " deleted." << endl;
    }

    // Add an edge
    void addEdge(int src, int dest, bool isDirected = false) {
        if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
            cout << "Invalid vertex ID(s)." << endl;
            return;
        }

        adjList[src].push_back(dest);
        if (!isDirected) {
            adjList[dest].push_back(src);
        }
        cout << "Edge added between " << src << " and " << dest << "." << endl;
    }

    // Delete an edge
    void deleteEdge(int src, int dest) {
        if (src >= vertices || dest >= vertices || src < 0 || dest < 0) {
            cout << "Invalid vertex ID(s)." << endl;
            return;
        }

        adjList[src].erase(remove(adjList[src].begin(), adjList[src].end(), dest), adjList[src].end());
        adjList[dest].erase(remove(adjList[dest].begin(), adjList[dest].end(), src), adjList[dest].end());

        cout << "Edge deleted between " << src << " and " << dest << "." << endl;
    }

    // Get all neighbors of a vertex
    void getNeighbors(int v) {
        if (v < 0 || v >= vertices) {
            cout << "Invalid vertex ID." << endl;
            return;
        }

        cout << "Neighbors of vertex " << v << ": ";
        for (int neighbor : adjList[v]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // Check if two vertices are connected
    void isConnected(int v1, int v2) {
        if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices) {
            cout << "Invalid vertex ID(s)." << endl;
            return;
        }

        if (find(adjList[v1].begin(), adjList[v1].end(), v2) != adjList[v1].end()) {
            cout << "Vertex " << v1 << " and " << v2 << " are connected." << endl;
        } else {
            cout << "Vertex " << v1 << " and " << v2 << " are not connected." << endl;
        }
    }

    // Search for a vertex
    void searchVertex(int v) {
        if (v < 0 || v >= vertices) {
            cout << "Vertex " << v << " does not exist." << endl;
        } else {
            cout << "Vertex " << v << " exists in the graph." << endl;
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
    Graph graph(5); // Example with 5 vertices

    int choice, src, dest;

    do {
        cout << "\nGraph Operations:\n";
        cout << "1. Add Vertex\n";
        cout << "2. Update Vertex\n";
        cout << "3. Delete Vertex\n";
        cout << "4. Add Edge\n";
        cout << "5. Delete Edge\n";
        cout << "6. Get All Neighbors of Vertex\n";
        cout << "7. Check if Two Vertices are Connected\n";
        cout << "8. Search Vertex\n";
        cout << "9. Display Graph\n";
        cout << "10. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                graph.addVertex();
                break;
            case 2:
                cout << "Enter vertex to update: ";
                cin >> src;
                cout << "Enter new vertex ID: ";
                cin >> dest;
                graph.updateVertex(src, dest);
                break;
            case 3:
                cout << "Enter vertex to delete: ";
                cin >> src;
                graph.deleteVertex(src);
                break;
            case 4:
                cout << "Enter source and destination vertices: ";
                cin >> src >> dest;
                graph.addEdge(src, dest);
                break;
            case 5:
                cout << "Enter source and destination vertices to delete edge: ";
                cin >> src >> dest;
                graph.deleteEdge(src, dest);
                break;
            case 6:
                cout << "Enter vertex to get neighbors: ";
                cin >> src;
                graph.getNeighbors(src);
                break;
            case 7:
                cout << "Enter two vertices to check connection: ";
                cin >> src >> dest;
                graph.isConnected(src, dest);
                break;
            case 8:
                cout << "Enter vertex to search: ";
                cin >> src;
                graph.searchVertex(src);
                break;
            case 9:
                cout << "Graph representation (Adjacency List):" << endl;
                graph.displayGraph();
                break;
            case 10:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
