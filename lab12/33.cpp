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

    void addEdge(int u, int v, int w) {
        if (u < V && v < V && u >= 0 && v >= 0)
            adjMatrix[u][v] = w;
        else
            cout << "Invalid vertices!\n";
    }

    void dijkstra(int start) {
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);

        dist[start] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = -1, minDist = INF;
            for (int i = 0; i < V; ++i) {
                if (!visited[i] && dist[i] < minDist) {
                    u = i;
                    minDist = dist[i];
                }
            }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && adjMatrix[u][v] && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        cout << "Vertex\tDistance from Source " << start << "\n";
        for (int i = 0; i < V; ++i)
            cout << i << "\t" << dist[i] << "\n";
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    do {
        cout << "\n1. Add Edge\n2. Find Shortest Path using Dijkstra's Algorithm\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter vertices (u v) and weight: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            int src;
            cout << "Enter source vertex: ";
            cin >> src;
            if (src >= 0 && src < V)
                g.dijkstra(src);
            else
                cout << "Invalid source vertex!\n";
        }

    } while (choice != 3);

    return 0;
}
