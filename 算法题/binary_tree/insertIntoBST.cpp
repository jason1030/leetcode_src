#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class recursion{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root==NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if(root->val> val) root->left = insertIntoBST(root->left, val);
        if(root->val< val) root->right = insertIntoBST(root->right, val);

        return root;
    }
};


class iteration{
public:
    TreeNode * insertIntoBST(TreeNode* root, int val){
        if(root==NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        TreeNode* cur = root;
        TreeNode* parent = root;
        while(cur!=NULL){
            parent = cur;
            if(cur->val>val) cur =cur->left;
            else cur =cur->right;
        }
        TreeNode* node = new TreeNode(val);
        if(cur->val>val) parent->left =node;
        else parent->right =node;
        return root;
    }
};