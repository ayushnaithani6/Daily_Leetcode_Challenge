#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
	int v;
	int *parent;
	int *rank;
	DisjointSet(int v) {
		parent = new int[v];
		rank = new int[v];
		for(int i=0; i<v; ++i) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	
	int findSet(int x) {
		if(x == parent[x]) return x;
		return findSet(parent[x]);
	}
	
	void unionSets(int x, int y) {
		x = findSet(x);
		y = findSet(y);
		if(x != y) parent[y] = x;
	}
	
	void unionSetsByRank(int x, int y) {
		x = findSet(x);
		y = findSet(y);
		if(x != y) {
			if(rank[x] < rank[y]) swap(x, y);
			parent[y] = x;
			if(rank[x] == rank[y]) ++rank[x];
		}
	}
};

int main() {
	int v = 5;
	DisjointSet *s = new DisjointSet(v);
	s->unionSets(1, 2);
	for(int i=0; i<5; ++i) {
		cout << s->parent[i] << " ";
	}
	return 0;
}