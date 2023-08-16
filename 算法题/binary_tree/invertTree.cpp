#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution{
public:
    TreeNode* recursionInvertTree(TreeNode* root){
        if(root ==NULL) return root;
        swap(root->left, root->right);
        recursionInvertTree(root->left);
        recursionInvertTree(root->right);
        return root;
    }

    TreeNode* iterateInvertTree(TreeNode* root){
        if(root==NULL) return root;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

        }
        return root;
    }

    TreeNode* uniIterateInvertTree(TreeNode* root){
        if(root==NULL) return root;
        stack<TreeNode*> st;
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node!=NULL){
                st.pop();
                if (node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);
            }

            else{
                st.pop();
                node =st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        
        return root;
    }

    TreeNode* levelInvertTree(TreeNode* root){
        queue<TreeNode*> que;
        if(root==NULL) return root;
        while(!que.empty()){
            int size = que.size();
            for(int i =0;i<size;i++){
                TreeNode* node =que.front();
                que.pop();
                swap(node->left, node->right);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return root;
    }
};