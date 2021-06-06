#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int *a, int *tree, int l, int r, int treeNode) {
    if(l == r) {
        tree[treeNode] = a[l];
        return;
    }
    int m = l+(r-l)/2;
    buildSegmentTree(a, tree, l, m, 2*treeNode+1);
    buildSegmentTree(a, tree, m+1, r, 2*treeNode+2);
    tree[treeNode] = tree[2*treeNode+1] + tree[2*treeNode+2];
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9};
    // 2*n-1 nodes in tree 
    int tree[17] = {0};
    buildSegmentTree(a, tree, 0, 8, 0);
    for(int i=0; i<17; ++i) {
        cout << tree[i] << " "; 
    }
    return 0;
}


// 0th index store array sum
// 1st index store left half sum
// 2nd index store right half sum
// and so on..
