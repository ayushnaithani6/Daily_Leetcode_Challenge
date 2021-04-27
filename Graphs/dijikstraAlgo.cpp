#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int v;
        // pair<int, int> is storing destination + edge weight
        vector<pair<int, int>> *adjList;

        Graph(int v) {
            this->v = v;
            adjList = new vector<pair<int, int>>[v];
        }

        void addEdge(int u, int v, int w) {
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
};


// function declarations
Graph* createGraph(void);
void printGraph(Graph*);
void shortestPath(int, vector<pair<int, int>>*&, int);
void printShortestDistances(vector<int>&, int);
void printShortestPaths(vector<int>&, int);
void printShortestPathsUtil(vector<int>&, int);


int main() {
    Graph *g = createGraph();
    int v = g->v;
    vector<pair<int, int>> *adjList = g->adjList;

    shortestPath(v, adjList, 0);

    return 0;
}


// shortest Path function
void shortestPath(int v, vector<pair<int, int>> *&adjList, int src) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, INT_MAX);
    vector<int> parent(v, -1);  // storing parent

    // initially we are at src cost from src to src = 0
    pq.push({0, src});
    dist[src] = 0;


    while(!pq.empty()) {
        pair<int, int> curSmallest = pq.top();
        int u = curSmallest.second;
        pq.pop();

        for(pair<int, int> connectedNode: adjList[u]) {
            int v = connectedNode.first;
            int weight = connectedNode.second;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }

    }

    printShortestDistances(dist, v);
    cout << endl;
    cout << "paths are: " << endl;
    printShortestPaths(parent, v);

}

void printShortestDistances(vector<int> &dist, int v) {
    for(int i=0; i<v; ++i) {
        cout << i << " -> " << dist[i] << endl;
    }
}

void printShortestPaths(vector<int> &parent, int v) {
    for(int i=0; i<v; ++i) {
        cout << "Shortest Path for " << i << " is   ";
        printShortestPathsUtil(parent, i);
        cout << endl;
    }
}

void printShortestPathsUtil(vector<int> &parent, int u) {
    if(parent[u] == -1) {
        cout << u;
        return;
    }

    printShortestPathsUtil(parent, parent[u]);
    cout << "->" << u;
}



// graph creation and printing
Graph* createGraph() {
    Graph *g = new Graph(9);
    g->addEdge(0, 1, 4);
    g->addEdge(0, 7, 8);
    g->addEdge(1, 2, 8);
    g->addEdge(1, 7, 11);
    g->addEdge(2, 3, 7);
    g->addEdge(2, 8, 2);
    g->addEdge(2, 5, 4);
    g->addEdge(3, 4, 9);
    g->addEdge(3, 5, 14);
    g->addEdge(4, 5, 10);
    g->addEdge(5, 6, 2);
    g->addEdge(6, 7, 1);
    g->addEdge(6, 8, 6);
    g->addEdge(7, 8, 7);
    return g;
}

void printGraph(Graph *g) {
    int vertices = g->v;
    vector<pair<int, int>> *adjacencyList = g->adjList;

    for(int i=0; i<vertices; ++i) {
        cout << i << " -> ";
        for(int j=0; j<adjacencyList[i].size(); ++j) {
            cout <<  "(" << adjacencyList[i][j].first << ", " << adjacencyList[i][j].second << ") " ;
        }
        cout << endl;
    }
}
