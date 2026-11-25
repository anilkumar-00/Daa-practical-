
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    Edge edges[100];

    cout << "Enter u v weight:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].w;
    }

    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0, count = 0;

    cout << "Selected edges:\n";

    for (int i = 0; i < E; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].w << endl;

            parent[u] = v;
            cost += edges[i].w;
            count++;
        }
    }

    if (count != V - 1)
        cout << "Graph is disconnected\n";
    else
        cout << "Minimum cost = " << cost;

    return 0;
}
