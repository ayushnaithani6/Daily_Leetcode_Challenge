// O(n) time complexity worst case
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
pair<int, int> diameterOfTree(TreeNode*);


int main() {
    TreeNode *root = treeSampleInput();
    cout << diameterOfTree(root).first;
    return 0;
}

// idea is to return a pair and calling a function once
// height and diameter together
pair<int, int> diameterOfTree(TreeNode *root) {
    if(root == NULL) {
        return {0, 0};
    }

    pair<int, int> leftAns = diameterOfTree(root->left);
    pair<int, int> rightAns = diameterOfTree(root->right);
    
    //  first value in pair is storing diameter and second is storing height
    
    int ld = leftAns.first;
    int rd = rightAns.first;
    int lh = leftAns.second;
    int rh = rightAns.second;

    return {max(max(lh+rh, ld), rd), 1+max(lh, rh)};
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