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
void inorderTraversal(TreeNode*);

int main() {
    TreeNode *root = treeSampleInput();
    inorderTraversal(root);
    return 0;
}

void inorderTraversal(TreeNode* root) {
    unordered_map<TreeNode*, int> cnt;
    stack<TreeNode*> stackFrame;
    stackFrame.push(root);

    while(!stackFrame.empty()) {
        TreeNode *curNode = stackFrame.top();
        if(curNode == NULL) {
            stackFrame.pop();
            continue;
        }
        else if(cnt[curNode] == 0) {
            cout << curNode->val << " ";
        }
        else if(cnt[curNode] == 1) {
            stackFrame.push(curNode->left);
        }
        else if(cnt[curNode] == 2) {
            stackFrame.push(curNode->right);
        }
        else {
            stackFrame.pop();
        }
        ++cnt[curNode];
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