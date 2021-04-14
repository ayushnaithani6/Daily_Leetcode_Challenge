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
pair<int, bool> isBalanced(TreeNode*);

int main() {
    TreeNode *root = treeSampleInput();
    cout << isBalanced(root).second;
    return 0;
}

pair<int, bool> isBalanced(TreeNode *root) {
    if(root == NULL) {
        return {0, true};
    }
    
    pair<int, bool> leftHalf = isBalanced(root->left);
    pair<int, bool> rightHalf = isBalanced(root->right);
    
    int lh = leftHalf.first;
    int rh = rightHalf.first;
    int isLeftBalanced = leftHalf.second;
    int isRightBalanced = rightHalf.second;
    
    int curHeight = 1 + max(lh, rh);
    bool isCurBalanced = (abs(lh-rh) <= 1);
    
    return {curHeight, (isCurBalanced && isLeftBalanced && isRightBalanced)};
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