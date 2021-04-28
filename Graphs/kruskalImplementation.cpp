//TIME COMPLEXITY: O(ElogE + ElogV)
//ElogE for sorting E edges in edge_list
//ElogV for applying FIND & UNION operations on E edges having V vertices


#include <bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int v;
        vector<pair<int, int>> *adj;
        vector<pair<int, pair<int, int>>> edgeList;

        Graph(int v) {
            this->v = v;
            adj = new vector<pair<int, int>>[v];
        }

        void addEdge(int u, int v, int w) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            edgeList.push_back({w, {u, v}});
        }
};

class DisjointSet {
    public:
        int *parent;
        int n;

        DisjointSet(int n) {
            this->n = n;
            parent = new int[n];
            for(int i=0; i<n; ++i) {
                parent[i] = i;
            }
        }

        int findParent(int a) {
            if(parent[a] == a) {
                return a;
            }

            int representative = findParent(parent[a]);
            parent[a] = representative;
            return representative;
        }

        bool unionSet(int a, int b) {
            int setRepresentativeOfa = findParent(a);
            int setRepresentativeOfb = findParent(b);

            if(setRepresentativeOfa == setRepresentativeOfb) {
                return true;
            }
            parent[setRepresentativeOfa] = setRepresentativeOfb;
            return false;
        }
};


int kruskalMST(vector<pair<int, pair<int, int>>> &edgeList, int v, vector<int> &includedEdges) {
    int totalEdgesInMST = v-1;
    int curEdgesInMST = 0;
    DisjointSet *vertexSet = new DisjointSet(v);
    int totalCost = 0;

    for(int i=0; i<edgeList.size(); ++i) {
        if(curEdgesInMST == totalEdgesInMST) {
            break;
        }
        pair<int, pair<int, int>> curEdge = edgeList[i];
        int u = curEdge.second.first;
        int v = curEdge.second.second;
        int weight = curEdge.first;
        if(!vertexSet->unionSet(u, v)) {
            totalCost += weight;
            includedEdges[i] = 1;
            ++curEdgesInMST;
        }
    }

    return totalCost;
}



int main() {
    Graph *g = new Graph(4);
    g->addEdge(0, 1, 10);
    g->addEdge(0, 2, 6);
    g->addEdge(0, 3, 5);
    g->addEdge(1, 3, 15);
    g->addEdge(2, 3, 4);

    vector<pair<int, pair<int, int>>> edgeList = g->edgeList;
    // edge list sorted on bases of weights
    sort(edgeList.begin(), edgeList.end());
    // for(int i=0; i<edgeList.size(); ++i) {
    //     cout << edgeList[i].second.first << " " << edgeList[i].second.second << " " << edgeList[i].first;
    //     cout << endl;
    // }

    vector<int> includedEdges(edgeList.size(), 0);
    cout << kruskalMST(edgeList, g->v, includedEdges) << endl;
    for(int i=0; i<edgeList.size(); ++i) {
        // according to sorted edgeList above
        cout << includedEdges[i] << " ";
    }
    return 0;
}
