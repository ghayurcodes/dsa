#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Edge Class
class Edge {
public:
    int DestinationVertexID;
    int weight;

    // Default Constructor
    Edge() {}

    // Parameterized Constructor
    Edge(int destVID, int w) {
        DestinationVertexID = destVID;
        weight = w;
    }

    void setEdgeValue(int destVID, int w) {
        DestinationVertexID = destVID;
        weight = w;
    }

    void setWeight(int w) {
        weight = w;
    }

    int getDestinationVertexID() {
        return DestinationVertexID;
    }

    int getWeight() {
        return weight;
    }
};

// Vertex Class
class Vertex {
public:
    int state_id;
    string state_name;
    list<Edge> edgeList; // List to store edges

    // Default Constructor
    Vertex() {
        state_id = 0;
        state_name = "";
    }

    // Parameterized Constructor
    Vertex(int id, string sname) {
        state_id = id;
        state_name = sname;
    }

    int getStateID() {
        return state_id;
    }

    string getStateName() {
        return state_name;
    }

    void setID(int id) {
        state_id = id;
    }

    void setStateName(string sname) {
        state_name = sname;
    }

    list<Edge> getEdgeList() {
        return edgeList;
    }
};

// Graph Class
class Graph {
public:
    vector<Vertex> vertices; // Vector of vertices

    void addVertex(Vertex newVertex) {
        bool check = checkIfVertexExistByID(newVertex.getStateID());
        if (check) {
            cout << "Vertex with this ID already exists." << endl;
        } else {
            vertices.push_back(newVertex);
            cout << "New Vertex added successfully." << endl;
        }
    }

    bool checkIfVertexExistByID(int vid) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).getStateID() == vid) {
                return true;
            }
        }
        return false;
    }

    // Other graph operations can be implemented here
};

int main() {
    int option, id1;
    Graph g;
    string sname;
    Vertex v1;

    do {
        cout << "Select an option:" << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Exit" << endl;
        cin >> option;

        switch (option) {
        case 1:
            cout << "Add Vertex Operation..." << endl;
            cout << "Enter State ID: ";
            cin >> id1;
            cout << "Enter State Name: ";
            cin >> sname;
            v1.setID(id1);
            v1.setStateName(sname);
            g.addVertex(v1);
            break;

        case 2:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option. Try again." << endl;
        }
    } while (option != 2);

    return 0;
}
