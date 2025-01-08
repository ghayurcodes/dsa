#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> adjMatrix(n,vector<int>(n, 0));

    // Adding edges
    adjMatrix[0][1] = 1; // Edge between 0 and 1
    adjMatrix[1][2] = 1; // Edge between 1 and 2

    // Display adjacency matrix
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
