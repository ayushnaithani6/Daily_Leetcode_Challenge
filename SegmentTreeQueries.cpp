#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int *a, int *tree, int l, int r, int pos) {
    if(l == r) {
        tree[pos] = a[l];
        return;
    }
    int m = l+(r-l)/2;
    buildSegmentTree(a, tree, l, m, 2*pos+1);
    buildSegmentTree(a, tree, m+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

// querys on segment tree
// update and range sum

// range sum query
// total participation, partial participation, no participation
int rangeSum(int *tree, int ql, int qr, int l, int r, int pos) {
    // total participation
    if(ql <= l && qr >= r) {
        return tree[pos];
    }
    // no participation
    if(ql > r || qr < l) {
        return 0;
    }
    // partial participation
    int m = l+(r-l)/2;
    return rangeSum(tree, ql, qr, l, m, 2*pos+1) + rangeSum(tree, ql, qr, m+1, r, 2*pos+2);
}

// update 
void update(int *tree, int idx, int newVal, int l, int r, int pos) {
    if(idx < l || idx > r) {
        return;
    }
    if(l == idx && r == idx) {
        tree[pos] = newVal;
        return;
    }

    int m = l+(r-l)/2;
    update(tree, idx, newVal, l, m, 2*pos+1);
    update(tree, idx, newVal, m+1, r, 2*pos+2);
    tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9};
    // 2*n-1 nodes in tree 
    int tree[17] = {0};
    buildSegmentTree(a, tree, 0, 8, 0);
    // for(int i=0; i<17; ++i) {
    //     cout << tree[i] << " "; 
    // }
    cout << rangeSum(tree, 2, 4, 0, 8, 0) << endl;
    update(tree, 2, 10, 0, 8, 0);
    for(int i=0; i<17; ++i) {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << rangeSum(tree, 2, 4, 0, 8, 0) << endl;
    return 0;
}


// 0th index store array sum
// 1st index store left half sum
// 2nd index store right half sum
// and so on..
