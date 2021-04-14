#include <bits/stdc++.h>
using namespace std;

// TreeNode 
class TreeNode {
    public:
        int val;
        TreeNode *left, *right;

        TreeNode(int val) {
            this->val = val;
            left = right = NULL;
        }
};

// function declarations
TreeNode* treeSampleInput(void);
void verticalOrder(TreeNode*);
void verticalOrderUtil(TreeNode*, unordered_map<int, vector<int>>&, int);


int main() {
    TreeNode *root = treeSampleInput();
    verticalOrder(root);
    return 0;
}


void verticalOrder(TreeNode *root) {
    unordered_map<int, vector<int>> store;

    verticalOrderUtil(root, store, 0);
    // printing store
    for(auto it: store) {
        cout << it.first << " ";
        for(int i=0; i<it.second.size(); ++i) {
            cout << it.second[i] << " ";
        }
        cout << endl;
    }

}

void verticalOrderUtil(TreeNode *root, unordered_map<int, vector<int>> &store, int hd) {
    if(root == nullptr) {
        return;
    }

    if(store.find(hd) != store.end()) {
        store[hd].push_back(root->val);
    } else {
        store[hd] = {root->val};
    }

    verticalOrderUtil(root->left, store, hd-1);
    verticalOrderUtil(root->right, store, hd+1);
}


TreeNode* treeSampleInput() {
    // sample Tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    

    //          5
    //         /\
    //       3   7
    //      / |  |\
    //     2  4  6 8
    // 
    return root;
}