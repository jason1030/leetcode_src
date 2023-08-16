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

class Solution {
public:
    //前序遍历
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*>  st;
        vector<int> result;
        if(root==NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node =st.top();
            st.pop();
            result.push_back(node->val);
            //注意这里入栈顺序应该是先右后左这样才能保证出栈时先左后右
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }

        return result;
    }
    //中序遍历
    // 处理：将当前节点值加入到result数组中；访问：遍历节点
    //不同于先序遍历，中序遍历的处理顺序和访问顺序是不一致的，所以要借助一个临时指针来访问节点
    vector<int> inorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* cur =root;
        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur =cur->left; //左
            }
            else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val); //中
                cur =cur->right;//右
            }
        }
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root){
        stack<TreeNode*> st;
        vector<int> result;
        if(root ==NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node =st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};