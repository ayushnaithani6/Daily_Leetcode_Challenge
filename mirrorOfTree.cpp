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
void mirror(TreeNode*);
void traverse(TreeNode*);


int main() {
    TreeNode *root = treeSampleInput();
    cout << "before : ";
    traverse(root);
    cout << endl;
    mirror(root);
    cout << "after : ";
    traverse(root);
    cout << endl;
    return 0;
}

void mirror(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

void traverse(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *curNode = q.front();
        cout << curNode->val << " ";
        q.pop();
        if(curNode->left) {
            q.push(curNode->left);
        }
        if(curNode->right) {
            q.push(curNode->right);
        }
    } 
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