#include <iostream>
#include <string>
using namespace std;

class Graph {
    int V;
    string cityNames[20];
    int cost[20][20];

public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cost[i][j] = 0;
            }
        }
    }

    void addCity(int index, string name) {
        cityNames[index] = name;
    }

    int getCityIndex(string name) {
        for (int i = 0; i < V; i++) {
            if (cityNames[i] == name)
                return i;
        }
        return -1;
    }

    void addEdge(string u, string v, int c) {
        int i = getCityIndex(u);
        int j = getCityIndex(v);
        if (i != -1 && j != -1) {
            cost[i][j] = c;
            cost[j][i] = c;
        }
    }

    void DFS(int v, bool visited[]) {
        visited[v] = true;
        for (int i = 0; i < V; i++) {
            if (cost[v][i] != 0 && !visited[i])
                DFS(i, visited);
        }
    }

    bool isConnected() {
        bool visited[20] = {false};
        DFS(0, visited);
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }

    void printGraph() {
        cout << "\nFlight Graph (Adjacency Matrix):\n";
        cout << "\t";
        for (int i = 0; i < V; i++)
            cout << cityNames[i] << "\t";
        cout << "\n";
        for (int i = 0; i < V; i++) {
            cout << cityNames[i] << "\t";
            for (int j = 0; j < V; j++) {
                cout << cost[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n, e;
    cout << "Enter number of cities: ";
    cin >> n;
    Graph g(n);

    cout << "Enter city names:\n";
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        g.addCity(i, name);
    }

    cout << "Enter number of flight paths: ";
    cin >> e;
    cout << "Enter flight paths (City1 City2 Cost):\n";
    for (int i = 0; i < e; i++) {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        g.addEdge(c1, c2, cost);
    }

    g.printGraph();

    if (g.isConnected())
        cout << "The flight network is CONNECTED.\n";
    else
        cout << "The flight network is NOT CONNECTED.\n";

    return 0;
}
