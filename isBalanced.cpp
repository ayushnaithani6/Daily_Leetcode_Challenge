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
bool isBalanced(TreeNode*);
int height(TreeNode*);

int main() {
    TreeNode *root = treeSampleInput();
    cout << isBalanced(root);
    return 0;
}

bool isBalanced(TreeNode *root) {
    if(root == NULL) {
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
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