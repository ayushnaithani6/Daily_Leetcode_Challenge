#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int v;
        vector<int> *adjList;

        Graph(int v) {
            this->v = v;
            adjList = new vector<int>[v];
        }

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
        }
};

// function declarations
Graph* createGraph(void);
void printGraph(Graph*);
bool detectCycle(Graph*);
bool detectCycleUtil(int , vector<int>*&, vector<bool>&, vector<bool>&, int);


int main() {
    Graph *g = createGraph();
    // printGraph(g);
    cout << detectCycle(g);
    return 0;
}

bool detectCycle(Graph *g) {
    int v = g->v;
    vector<int> *adjList = g->adjList;
    // taking visited and storing ancestor in this case
    vector<bool> ancestor(v, false);
    vector<bool> visited(v, false);
    for(int i=0; i<v; ++i) {
        if(detectCycleUtil(v, adjList, visited, ancestor, i)) {
            return true;
        }
    }
    return false;
}

bool detectCycleUtil(int v, vector<int> *&adjList, vector<bool> &visited, vector<bool> &ancestor, int src) {

    if(!visited[src]) {
        visited[src] = true;
        ancestor[src] = true;

        for(int connectedNode: adjList[src]) {
            if(ancestor[connectedNode]) {
                return true;
            }
            else {
                if(detectCycleUtil(v, adjList, visited, ancestor, connectedNode)) {
                    return true;
                }
            }
        }
    }
    ancestor[src] = false;
    return false;
}


Graph* createGraph() {
    Graph *g = new Graph(5);
    // we have cycle in this graph
    g->addEdge(0, 1); 
    g->addEdge(0, 2); 
    g->addEdge(2, 3); 
    g->addEdge(3, 4); 
    g->addEdge(4, 3);
    
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