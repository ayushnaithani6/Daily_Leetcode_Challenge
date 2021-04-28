#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

class Graph {
    public:
        int v;
        vector<pii> *adj;
        
        Graph(int v) {
            this->v = v;
            adj = new vector<pii>[v];
        }

        void addEdge(int u, int v, int w) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
};

void primsMST(int v, vector<pii> *&adj, int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(v, false);
    vector<int> dist(v, INT_MAX);

    pq.push({0, src});
    dist[src] = 0;
    
    vector<int> parent(v, -1);

    while(!pq.empty()) {
        int u = pq.top().second;
        visited[u] = true;
        pq.pop();

        for(pii connectedNode: adj[u]) {
            int v = connectedNode.first;
            int weight = connectedNode.second;

            if(!visited[v] && dist[v] > weight) {
                dist[v] = weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=0; i<v; ++i) {
        // sum gives totalCost
        cout << dist[i] << " ";
    }

    cout << endl;

    for(int i=0; i<v; ++i) {
        // edges included
        cout << i << " - " << parent[i] << endl;
    }
}


int main() {
    Graph *g = new Graph(4);
    g->addEdge(0, 1, 5);
    g->addEdge(0, 2, 5);
    g->addEdge(0, 3, 5);
    g->addEdge(1, 3, 1);
    g->addEdge(2, 3, 1);

    primsMST(g->v, g->adj, 0);
}
