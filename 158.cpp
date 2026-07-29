#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add a directed edge from u to v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to detect cycle using Kahn's Algorithm (BFS)
    bool isCyclic() {
        vector<int> in_degree(V, 0);

        // Step 1: Calculate the in-degree of each vertex
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                in_degree[v]++;
            }
        }

        // Step 2: Push all vertices with an in-degree of 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Standard BFS processing
        int visited_count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited_count++; // Track how many nodes are successfully processed

            // Loop through all neighbors of the current node
            for (int v : adj[u]) {
                // Reduce the in-degree of the neighbor
                in_degree[v]--;
                
                // If in-degree becomes 0, add it to the queue
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Step 4: If visited nodes match total nodes, there is NO cycle
        // If they do not match, a cycle is present.
        return (visited_count != V);
    }
};

int main() {
    // Example 1: Graph with a cycle (2 -> 3 -> 4 -> 2)
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    g1.addEdge(4, 2); // Creates the cycle

    if (g1.isCyclic()) {
        cout << "Graph 1 contains a cycle." << endl;
    } else {
        cout << "Graph 1 does not contain a cycle." << endl;
    }

    // Example 2: Acyclic Graph (DAG)
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);

    if (g2.isCyclic()) {
        cout << "Graph 2 contains a cycle." << endl;
    } else {
        cout << "Graph 2 does not contain a cycle." << endl;
    }

    return 0;
}
