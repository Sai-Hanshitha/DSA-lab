#include <iostream>
using namespace std;

class GraphMatrix {
    int **adjMatrix;
    int numVertices;

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void insertEdge(int i, int j) {
        if (i >= 0 && j >= 0 && i < numVertices && j < numVertices)
            adjMatrix[i][j] = adjMatrix[j][i] = 1;
        else
            cout << "Invalid edge!\n";
    }

    void deleteEdge(int i, int j) {
        if (i >= 0 && j >= 0 && i < numVertices && j < numVertices)
            adjMatrix[i][j] = adjMatrix[j][i] = 0;
        else
            cout << "Invalid edge!\n";
    }

    void searchEdge(int i, int j) {
        if (adjMatrix[i][j])
            cout << "Edge exists between " << i << " and " << j << endl;
        else
            cout << "No edge exists.\n";
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    ~GraphMatrix() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    int v, choice, i, j;
    cout << "Enter number of vertices: ";
    cin >> v;

    GraphMatrix graph(v);

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
