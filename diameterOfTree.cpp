// time complexity O(nlogn) --> balanced tree
// O(n^2) for skewed tree
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
int diameterOfTree(TreeNode*);
int height(TreeNode*);

int main() {
    TreeNode *root = treeSampleInput();
    cout << diameterOfTree(root);
    return 0;
}

int diameterOfTree(TreeNode *root) {
    if(root == NULL) {
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);

    return max(diameterOfTree(root->left), max(diameterOfTree(root->right), lh+rh));
}

int height(TreeNode *root) {
    if(root == NULL) {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}



TreeNode* treeSampleInput() {
    // sample Tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(3);
    root->left->left->left->left = new TreeNode(6);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(7);
    root->right = new TreeNode(7);
    

    //          5
    //         /\
    //       3   7
    //      / |  |\
    //     2  4  6 8
    // 
    return root;
}