#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v, int w) {
        if (u >= 0 && v >= 0 && u < V && v < V)
            edges.push_back(Edge(u, v, w));
        else
            cout << "Invalid vertices!\n";
    }

    int findParent(int u, vector<int>& parent) {
        if (u != parent[u])
            parent[u] = findParent(parent[u], parent);
        return parent[u];
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), compareEdges);
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; ++i)
            parent[i] = i;

        cout << "Edge \tWeight\n";
        for (const Edge& e : edges) {
            int rootU = findParent(e.u, parent);
            int rootV = findParent(e.v, parent);
            if (rootU != rootV) {
                cout << e.u << " - " << e.v << "\t" << e.weight << "\n";
                unionSets(rootU, rootV, parent, rank);
            }
        }
    }
};

int main() {
    int V, choice;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);

    do {
        cout << "\n1. Add Edge\n2. Find MST using Kruskal's Algorithm\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "Enter vertices (u v) and weight: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (choice == 2) {
            g.kruskalMST();
        }

    } while (choice != 3);

    return 0;
}
