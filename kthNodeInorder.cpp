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
TreeNode* kThNode(TreeNode*, static int);

int main() {
    TreeNode *root = treeSampleInput();
    // code here
    static int curVal = 0;

    kThNode(root, );
    return 0;
}

TreeNode* KThNode(TreeNode *root, static int curVal) {
    if(root == nullptr) {
        return;
    }

    if(curVal == )
    KThNode(root->left, curVal);

    ++curVal;

    KthNode(root->left, curVal);

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