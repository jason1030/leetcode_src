# include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class solution{
public:
    TreeNode* searchBSTRecur(TreeNode* root, int val){
        if(root==nullptr||root->val==val) return root;
        if(root->val>val) return searchBSTRecur(root->left, val);
        if(root->val<val) return searchBSTRecur(root->right, val);
        return NULL;
    }

    TreeNode* searchBSTIter(TreeNode* root, int val){
        while(root!=NULL){
            if(root->val>val) root=root->left;
            if(root->val<val) root=root->right;
            else return root;
        }
        return NULL;
    }
};