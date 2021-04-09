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


        delete(int val) {
            
        }

};

int main() {
    Tree *t = new Tree();
    for(int i=1; i<=7; ++i) {
        t->levelOrderInsertion(i);
    }
    
    TreeNode *foundNode = t->search(10);
    return 0;
} 