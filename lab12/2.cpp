#include <iostream>
#include <list>
using namespace std;

class GraphList {
    int V;
    list<int> *adj;

public:
    GraphList(int vertices) {
        V = vertices;
        adj = new list<int>[V];
    }

    void insertEdge(int v, int w) {
        if (v < V && w < V) {
            adj[v].push_back(w);
            adj[w].push_back(v);
        } else {
            cout << "Invalid vertex!\n";
        }
    }

    void deleteEdge(int v, int w) {
        adj[v].remove(w);
        adj[w].remove(v);
    }

    void searchEdge(int v, int w) {
        for (int x : adj[v]) {
            if (x == w) {
                cout << "Edge exists between " << v << " and " << w << endl;
                return;
            }
        }
        cout << "No edge exists.\n";
    }

    void display() {
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (auto x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }

    ~GraphList() {
        delete[] adj;
    }
};

int main() {
    int v, choice, i, j;
    cout << "Enter number of vertices: ";
    cin >> v;

    GraphList graph(v);

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (i j): ";
                cin >> i >> j;
                graph.insertEdge(i, j);
                break;
            case 2:
                cout << "Enter edge (i j): ";
                cin >> i >> j;
                graph.deleteEdge(i, j);
                break;
            case 3:
                cout << "Enter edge (i j): ";
                cin >> i >> j;
                graph.searchEdge(i, j);
                break;
            case 4:
                graph.display();
                break;
        }
    } while (choice != 5);

    return 0;
}
