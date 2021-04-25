// detect if there is cycle in undirected Graph
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
bool detectCycle(Graph*);
bool detectCycleUtil(int, vector<int>*&, vector<bool>&, int, int);


int main() {
    Graph *g = createGraph();
    cout << detectCycle(g);
    return 0;
}

bool detectCycle(Graph *g) {
    int v = g->v;
    vector<int> *adjList = g->adjList;
    // idea is that do dfs for each verteces if we again visited any prev visited node except parent itself
    // then we found cycle
    vector<bool> isVisited(v, false);
    for(int i=0; i<v; ++i) {
        if(detectCycleUtil(v, adjList, isVisited, 0, -1)) return true;
    }
    return false;
}

bool detectCycleUtil(int v, vector<int> *&adjList, vector<bool> &isVisited, int src, int parent) {

    if(!isVisited[src]) {
        isVisited[src] = true;

        for(int connectedNode: adjList[src]) {
            if(connectedNode == parent) {
                continue;
            }
            if(isVisited[connectedNode]) {
                return true;
            }
            else {
                if(detectCycleUtil(v, adjList, isVisited, connectedNode, src)) {
                    return true;
                };
            }
        }
    }
    return false;
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