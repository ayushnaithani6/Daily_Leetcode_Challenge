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

Graph* createGraph() {
    Graph *g = new Graph(7);
    // DAG
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 4);
    g->addEdge(3, 5);
    g->addEdge(4, 5);
    g->addEdge(5, 6);
    return g;
}



void topSort(int v, vector<int> *&adjList, vector<bool> &visited, int src, vector<int> &ans) {
    if(!visited[src]) {
        visited[src] = true;
        for(int connectedNode: adjList[src]) {
            if(!visited[connectedNode]) {
                topSort(v, adjList, visited, connectedNode, ans);
            }
        }

        ans.push_back(src);
    }
}


int main() {
    Graph *g = createGraph();
    vector<int> ans;
    vector<bool> visited(g->v, false);

    for(int i=0; i<g->v; ++i)
        topSort(g->v, g->adjList, visited, i, ans);

    reverse(ans.begin(), ans.end());

    for(int i=0; i<g->v; ++i) 
        cout << ans[i];

    return 0;
}
