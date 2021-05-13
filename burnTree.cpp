#include <bits/stdc++.h>
#define ump unordered_map

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* createTree() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    return root;
}

TreeNode* findNode(TreeNode *root, int target) {
    if(root == nullptr) {
        return nullptr;
    }

    if(target == root->val) {
        return root;
    }

    TreeNode *left = findNode(root->left, target);
    TreeNode *right = findNode(root->right, target);

    if(left == nullptr && right == nullptr) {
        return nullptr;
    }
    return (left == nullptr) ? right : left;
}

void storeParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode *prev) {
    if(root == nullptr) {
        return;
    }
    parent[root] = prev;
    prev = root;
    storeParent(root->left, parent, prev);
    storeParent(root->right, parent, prev);
}

int minTimeUtil(TreeNode *root, TreeNode *targetNode, ump<TreeNode*, TreeNode*> &parent, ump<TreeNode*, bool> isVisited) {
    queue<pair<TreeNode*, int>> q;
    q.push({targetNode, 0});
    int maxLevel = 0;

    while(!q.empty()) {
        pair<TreeNode*, int> onTop = q.front();
        q.pop();
        TreeNode *curNode = onTop.first;
        int curLevel = onTop.second;
        if(curLevel > maxLevel) {
            maxLevel = curLevel;
        }

        if(isVisited[curNode] == false) {
            isVisited[curNode] = true;

            if(curNode->left && !isVisited[curNode->left]) {
                q.push({curNode->left, curLevel+1});
            }
            if(curNode->right && !isVisited[curNode->right]) {
                q.push({curNode->right, curLevel+1});
            }
            if(parent[curNode] && !isVisited[parent[curNode]]) {
                q.push({parent[curNode], curLevel+1});
            }
        }
    }
    return maxLevel;
}

int minTime(TreeNode *root, int target) {
    TreeNode *targetNode = findNode(root, target);
    ump<TreeNode*, TreeNode*> parent;
    TreeNode *prev = nullptr;
    storeParent(root, parent, prev);

    ump<TreeNode*, bool> isVisited;
    return minTimeUtil(root, targetNode, parent, isVisited);

}

int main() {
    TreeNode *root = createTree();
    int target = 3;
    cout << minTime(root, target);
    return 0;
}
