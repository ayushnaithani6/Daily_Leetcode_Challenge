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
void topOrderTraversal(TreeNode*);
void dfs(TreeNode*, map<int, int>&, int);


int main() {
    TreeNode *root = treeSampleInput();
    topOrderTraversal(root);
    return 0;
}

void topOrderTraversal(TreeNode *root) {
	map<int, int> store;
	dfs(root, store, 0);
	for(auto it: store) {
		cout << it.second << " ";
	}
}

void dfs(TreeNode *root, map<int, int> &store, int hd) {
	if(root == nullptr) {
		return;
	}
	if(store.find(hd) == store.end()) {
		store[hd] = root->val;
	}
	dfs(root->left, store, hd-1);
	dfs(root->right, store, hd+1);
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