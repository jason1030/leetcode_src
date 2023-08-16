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
    TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root->val> p->val && root->val >q->val){
            return lowestCommonAncestor_BST(root->left, p, q);
        }
        else if(root->val <p->val && root->val<q->val){
            return lowestCommonAncestor_BST(root->right, p, q);
        }

        else return root;
        
    }

};

class iteration{
public:
    TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q){
        while(root){
            if(root->val> p->val && root->val >q->val) root =root->left;
            else if(root->val <p->val && root->val<q->val) root = root->right;
            else return root;
        }

        return NULL;
    }
};