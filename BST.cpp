// see leetcode solution fully commented
// this solution have some corner cases to cover
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;

        TreeNode(int val) {
            this->val = val;
            left = right = NULL;
        }
};

void insertNode(TreeNode* &root, int val) {
    TreeNode *newNode = new TreeNode(val);
    if(root == NULL) {
        root = newNode;
        return;
    }

    TreeNode *curNode = root;
    TreeNode *prevNode = NULL;
    while(curNode != NULL) {
        if(curNode->val < val) {
            prevNode = curNode;
            curNode = curNode->right;
        }
        else {
            prevNode = curNode;
            curNode = curNode->left;
        }
    }
    if(prevNode->val > val) {
        prevNode->left = newNode;
    }
    else {
        prevNode->right = newNode;
    }
}


TreeNode* searchNode(TreeNode *root, int val) {
    if(root == NULL) {
        return NULL;
    }
    if(root->val == val) {
        return root;
    }

    if(root->val > val) {
        return searchNode(root->left, val);
    }
    return searchNode(root->right, val);
}


TreeNode* inorderPredecesor(TreeNode *root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        return root;
    }

    return inorderPredecesor(root->right);
}

TreeNode* searchParent(TreeNode *root, TreeNode *foundNode) {
    if(root == foundNode) {
        return NULL;
    }
    if(root->left == foundNode || root->right == foundNode) {
        return root;
    }
    if(foundNode->val < root->val) {
        return searchParent(root->left, foundNode);
    }
    return searchParent(root->right, foundNode);
}

void deleteNode(TreeNode* &root, int val) {
    // finding Node
    TreeNode *foundNode = searchNode(root, val);
    TreeNode *parentNode = searchParent(root, foundNode);

    if(foundNode == NULL) {
        return;
    }
    
    // if leaf Node
    if(!foundNode->left && !foundNode->right) {
        if(foundNode->val < parentNode->val) {
            parentNode->left = NULL;
        }
        else {
            parentNode->right = NULL;
        }
        delete foundNode;
        return;
    }

    // if Node to be deleted has only one child
    if(!foundNode->left || !foundNode->right) {
        if(foundNode->left) {
            int value = foundNode->left->val;
            deleteNode(foundNode->left, value);
            foundNode->val = value;
            return;
        }
        else {
            cout << foundNode->val << " ";
            int value = foundNode->right->val;
            deleteNode(foundNode, value);
            foundNode->val = value;
            return;
        }
    }

    // if both child are present
    // find inorder predecessor and replace value to foundNode
    // delete that inorder predecesor
    TreeNode *inorderPred = inorderPredecesor(foundNode->left);
    if(inorderPred) {
        int value = inorderPred->val;
        deleteNode(foundNode, value);
        foundNode->val = value;
    }
}











void inorder(TreeNode *root) {
    unordered_map<TreeNode*, int> cnt;
    stack<TreeNode*> stackFrame;
    stackFrame.push(root);

    while(!stackFrame.empty()) {
        TreeNode *curNode = stackFrame.top();
        if(curNode == NULL) {
            stackFrame.pop();
            continue;
        }
        if(cnt[curNode] == 0) {
            stackFrame.push(curNode->left);
        }
        else if(cnt[curNode] == 1) {
            cout << curNode->val << " ";
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

int main() {
    TreeNode *root = NULL;
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 8);
    inorder(root);
    deleteNode(root, 5);
    cout << endl;
    inorder(root);

}