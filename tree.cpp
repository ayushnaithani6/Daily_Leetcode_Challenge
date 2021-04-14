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

class Tree {
    public:
        TreeNode *root;

        Tree() {
            root = NULL;
        }

        void levelOrderInsertion(int val) {
            TreeNode *newNode = new TreeNode(val);
            if(root == NULL) {
                root = newNode;
                return;
            }

            queue<TreeNode*> q;
            q.push(root);

            //              1
            //          2       3
            //  1 2 3 4
            while(!q.empty()) {
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                else {
                    temp->left = newNode;
                    break;
                }

                if(temp->right != NULL) {
                    q.push(temp->right);
                }
                else {
                    temp->right = newNode;
                    break;
                }
            }
            return;
        }

        TreeNode* search(int val) {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                TreeNode *curNode = q.front();
                q.pop();
                if(curNode == NULL) {
                    continue;
                }
                if(curNode->val == val) {
                    return curNode;
                }
                else {
                    q.push(curNode->left);
                    q.push(curNode->right);
                }
            }
            return NULL;
        }

        TreeNode* deepSearch(void) {
            queue<TreeNode*> q;
            q.push(root);
            TreeNode *curNode = NULL;

            while(!q.empty()) {
                curNode = q.front();
                q.pop();

                if(curNode->left) {
                    q.push(curNode->left);
                }
                if(curNode->right) {
                    q.push(curNode->right);
                }
            }
            return curNode;
        }

        void deleteNode(int val) {
            // search for node to be delelted
            TreeNode *delNode = search(val);
            if(delNode != NULL) {
                if(delNode == root && !root->left && !root->right) {
                    root = NULL;
                    delete delNode;
                    return;
                }
                
                TreeNode *deepestNode = deepSearch();   // found deepest Node
                // idea is to delete that deepest Node and puting its value in delNode->val
                int newValue = deepestNode->val;
                // cout << deepestNode->val;
                if(deepestNode != delNode) {
                    deleteDeepNode(deepestNode);
                    delNode->val = newValue;
                }
                else {
                    deleteDeepNode(deepestNode);
                }
            }
            return;
        }

        void deleteDeepNode(TreeNode *deepestNode) { 
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                TreeNode *curNode = q.front();
                q.pop();

                if(curNode->right) {
                    if(curNode->right == deepestNode) {
                        curNode->right = NULL;
                        delete deepestNode;
                        return;
                    }
                    else {
                        q.push(curNode->right);
                    }
                }

                if(curNode->left) {
                    if(curNode->left == deepestNode) {
                        curNode->left = NULL;
                        delete deepestNode;
                        return;
                    }
                    else {
                        q.push(curNode->left);
                    }
                }
            }

        }

};

void traverse(TreeNode* root) {
    if(root == NULL) return;
    cout << root->val;
    traverse(root->left);
    traverse(root->right);
}

int main() {
    Tree *t = new Tree();
    for(int i=1; i<=7; ++i) {
        t->levelOrderInsertion(i);
    }

    t->deleteNode(5);
    
    traverse(t->root);
    cout << endl;
    
    t->deleteNode(4);
    
    traverse(t->root);
    cout << endl;
    
    t->deleteNode(1);
    
    traverse(t->root);
    cout << endl;
    
    return 0;
} 