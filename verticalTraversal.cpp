// vertical order traversal


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
void verticalTraversal(TreeNode*);
void findDistance(TreeNode*, int&, int&, int);
void printLeveli(TreeNode*, int, int);

int main() {
    TreeNode *root = treeSampleInput();
    verticalTraversal(root);
    return 0;
}

void verticalTraversal(TreeNode *root) {
    int leftMost = 0;
    int rightMost = 0;
    int curPos = 0;
    findDistance(root, leftMost, rightMost, curPos);

    for(int i=leftMost; i<=rightMost; ++i) {
        cout << "Values at vertical Level " << i << "       ";
        printLeveli(root, i, curPos);
        cout << endl;
    }
}

void findDistance(TreeNode *root, int &leftMost, int &rightMost, int curPos) {
    if(root == nullptr) {
        return;
    } 

    if(leftMost > curPos) {
        leftMost = curPos;
    }

    if(rightMost < curPos) {
        rightMost = curPos;
    }

    findDistance(root->left, leftMost, rightMost, curPos-1);
    findDistance(root->right, leftMost, rightMost, curPos+1);
}


void printLeveli(TreeNode *root, int i, int curPos) {
    if(root == nullptr) {
        return;
    }

    if(curPos == i) {
        cout << root->val << " ";
    }

    printLeveli(root->left, i, curPos-1);
    printLeveli(root->right, i, curPos+1);
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