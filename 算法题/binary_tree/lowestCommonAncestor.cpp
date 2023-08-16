
#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class solution{
public:
    TreeNode* lowestCommenAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root ==p || root ==q) return root;
        TreeNode* left = lowestCommenAncestor(root->left, p , q);
        TreeNode* right = lowestCommenAncestor(root->right, p , q);
        if(left!=NULL && right!=NULL) return root;

        if(left==NULL && right!=NULL) return right;
        else if(left!=NULL && right ==NULL )return left;
        else return NULL;
    }


};