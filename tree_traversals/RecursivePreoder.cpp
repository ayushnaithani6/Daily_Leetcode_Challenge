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
void preorderTraversal(TreeNode*);

int main() {
    TreeNode *root = treeSampleInput();
    preorderTraversal(root);
    return 0;
}

void preorderTraversal(TreeNode* root) {
    if(root == NULL) {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
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