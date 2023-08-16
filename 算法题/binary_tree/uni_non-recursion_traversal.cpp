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

/* 二叉树非递归（栈）遍历的统一写法
    在遍历过程中，在需要处理的节点入栈后再添加一个nullptr，这样出栈的时候可以保证nullptr之后的节点被处理
    等于是将遍历与处理节点分离，这样只需要在遍历节点的代码上略微 调整就可以轻松得到前中后序遍历的代码了
 */
class solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode* > st;
        if(root != NULL) st.push(root);
        
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(NULL);
                if(node->left) st.push(node->left);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }

        return result;
    }



    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode* > st;
        if(root != NULL) st.push(root);
        
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }

        return result;
    }


    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        stack<TreeNode* > st;
        if(root != NULL) st.push(root);
        
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node != NULL){
                st.pop();
                st.push(node);
                st.push(NULL);
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }

        return result;
    }
};