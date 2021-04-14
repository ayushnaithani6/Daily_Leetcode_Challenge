#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left, *right;
    int decendents;

    TreeNode(int val, int decendents) {
        this->val = val;
        this->decendents = decendents;
        left = right = nullptr;
    }
};

TreeNode* treeSampleInput() {
    // sample Tree
    TreeNode *root = new TreeNode(5, 6);
    root->left = new TreeNode(3, 2);
    root->left->left = new TreeNode(2, 0);
    root->left->right = new TreeNode(4, 0);
    root->right = new TreeNode(7, 2);
    root->right->left = new TreeNode(6, 0);
    root->right->right = new TreeNode(8, 0);
    

    //          5
    //         /\
    //       3   7
    //      / |  |\
    //     2  4  6 8
    // 
    return root;
}

TreeNode* getNode(TreeNode *root, int k) {
    if(root == nullptr) {
        return nullptr;
    }
    
    int left = (root->left == nullptr) ? 0 : root->left->decendents+1;

    if(left >= k) {
        return getNode(root->left, k);
    }

    else if(left+1 == k) {
        return root;
    }

    return getNode(root->right, k-left-1);
}

int main() {
    TreeNode *root = treeSampleInput();
    for(int i=1; i<=7; ++i) {
        TreeNode *found = getNode(root, i);
        cout << found->val;
    }

}

