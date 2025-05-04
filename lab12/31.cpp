#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices) : V(vertices) {
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        if (u < V && v < V && u >= 0 && v >= 0) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
        } else {
            cout << "Invalid vertices!\n";
        }
    }

    void primMST() {
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = -1, minKey = INF;
            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            if (u == -1) break;
            inMST[u] = true;

            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; ++i)
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << "\n";
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    do {
        cout << "\n1. Add Edge\n2. Find MST using Prim's Algorithm\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter vertices (u v) and weight: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.primMST();
        }

    } while (choice != 3);

    return 0;
}
