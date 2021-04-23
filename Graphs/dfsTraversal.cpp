#include <bits/stdc++.h>
using namespace std;

// my graph implementation
class Graph {
    public:
        int v;
        vector<int> *adjList;

        Graph(int v) {
            this->v = v;
            adjList = new vector<int>[v];
        }

        // edge consist of u -> source, v -> destination,
        // this is bidirectional graph 
        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

};

// function Declarations
Graph* createGraph(void);
void printGraph(Graph*);
void dfs(Graph*);
void dfsUtil(Graph*, vector<bool>&, int, vector<int>*&);

int main() {
    Graph *g = createGraph();
    dfs(g);
    return 0;
}


void dfs(Graph *g) {
    int v = g->v;
    vector<int> *adjList = g->adjList;
    vector<bool> isVisited(v, false);
    int src = 0;
    dfsUtil(g, isVisited, src, adjList);
}

void dfsUtil(Graph *g, vector<bool> &isVisited, int src, vector<int> *&adjList) {
    cout << src << " ";
    isVisited[src] = true;
    for(int i=0; i<adjList[src].size(); ++i) {
        if(!isVisited[adjList[src][i]]) {
            dfsUtil(g, isVisited, adjList[src][i], adjList);
        }
    } 
}

























Graph* createGraph() {
    Graph *g = new Graph(7);
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 3);
    g->addEdge(3, 4);
    g->addEdge(3, 6);
    g->addEdge(4, 5);
    g->addEdge(6, 5);

    return g;
}

void printGraph(Graph *g) {
    int vertices = g->v;
    vector<int> *adjacencyList = g->adjList;

    for(int i=0; i<vertices; ++i) {
        cout << i << " -> ";
        for(int j=0; j<adjacencyList[i].size(); ++j) {
            cout <<  adjacencyList[i][j] << " ";
        }
        cout << endl;
    }
}