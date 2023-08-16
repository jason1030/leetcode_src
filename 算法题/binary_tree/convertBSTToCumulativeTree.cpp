#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class recursion{
private:
    int pre;
    // BST的节点值是有序的，所以利用这个特点，进行反向中序遍历（右中左）即可
    void traversal(TreeNode* cur){
        if(cur==NULL)  return;
        traversal(cur->right);
        // pre记录遍历的上一节点，进行值累加
        cur->val +=pre;
        pre =cur->val;
        traversal(cur->left);
        
    }

public:
    TreeNode* convertBST(TreeNode* root){
        pre = 0;
        traversal(root);
        return root;
    }
};


class iteration{
private:
    int pre;
    void traversal(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* cur =root;
        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->right;
            }
            else {
                cur =st.top();
                st.pop();
                cur->val +=pre;
                pre = cur->val;
                cur = cur->left;
            }
            
        }
        
    }

public:
    TreeNode* convertBST(TreeNode* root){
        pre =0;
        traversal(root);
        return root;
    }
};