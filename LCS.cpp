#include <bits/stdc++.h>
using namespace std;

LCS(TreeNode *root, TreeNode *x, TreeNode *y) {
    if(root == NULL) {
        return NULL;
    }

    if(root == x || root == y) {
        return root;
    }

    TreeNode *left = LCS(root->left, x, y);
    TreeNode *right = LCS(root->right, x, y);

    if(left == NULL && right == NULL) {
        return NULL;
    }

    return (root->left) ? return root->left : return root->right;
}



int main() {

}