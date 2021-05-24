// implementation of directed graph cycle check
#include <bits/stdc++.h>
using namespace std;  

bool dfs(vector<int> *&adj, vector<bool> &ok, vector<bool> &dfsOk, int u) {
     ok[u] = true;
     dfsOk[u] = true;
     for(int i: adj[u]) {
          if(dfsOk[i] == true) {
               return true;
          }
          // if not visited then visit that node if cycle is detected 
          // while furthur dfs stop then n there and return 
          else if(!ok[i] && dfs(adj, ok, dfsOk, i)) return true;
     }
     dfsOk[u] = false;
     return false;
}

int main() {
     int V, E;
     cin >> V >> E;
     vector<int> *adj = new vector<int>[V];
     int u, v;
     while(E--) {
          cin >> u >> v;
          adj[u].push_back(v);
     }

     vector<bool> ok(V, false);
     vector<bool> dfsOk(V, false);
     for(int i=0; i<V; ++i) {
          if(!ok[i] && dfs(adj, ok, dfsOk, i)) {
               cout << "Cycle Detected :(";
               return 0;
          }
     }
     cout << "Cycle not found :)";
     return 0;
}
