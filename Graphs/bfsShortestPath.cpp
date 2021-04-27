// shortest path in unweighted graph can be found by bfs

#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int v;
        vector<int> *adj;
        Graph(int v) {
            this->v = v;
            adj = new vector<int>[v];
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
};


void printPath(vector<int> &parent, int dest) {
    if(parent[dest] == -1) {
        cout << dest;
        return;
    }
    printPath(parent, parent[dest]);
    cout << "->" << dest;
}

int bfs(int v, vector<int> *&adj, int src, int dest, vector<int> &parent) {
    vector<bool> visited(v, false);
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;

    while(!q.empty()) {
        pair<int, int> explore = q.front();
        q.pop();
        for(int connectedNode: adj[explore.first]) {
            if(!visited[connectedNode]) {
                // then push it to queue and mark it as visited
                q.push({connectedNode, explore.second + 1});
                parent[connectedNode] = explore.first;
                visited[connectedNode] = true;
            }
            if(connectedNode == dest) {
                return explore.second + 1;
            }
        }
    }

    return -1;
}

void shortestPath(int v, vector<int> *&adj, int src, int dest) {
    if(src == dest) {
        cout << "you are there already";
        return;
    }

    vector<int> parent(v, INT_MAX);
    parent[src] = -1;

    int val = bfs(v, adj, src, dest, parent);
    
    if(val == -1) {
        cout << "no path possible"; 
    }
    else {
        cout << "shortest possible path is of len " << val << endl;
        printPath(parent, dest);
    }
    
}

int main() {
    Graph *g = new Graph(8);
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(2, 5);
    g->addEdge(2, 6);

    shortestPath(g->v, g->adj, 3, 6);
    return 0;
}

