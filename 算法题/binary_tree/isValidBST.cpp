#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class solution{
public:
    // 常规版
    long long maxVal =LONG_MIN;
    bool isValidBST(TreeNode* root){
        if(root==NULL)  return true;
        
        bool left = isValidBST(root->left);
        if(maxVal<root->val) maxVal=root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
    // 改良版，不要设最小值了，防止出题人恶心人给你也设置个LONG_MIN，留一个pre指针来保存前一个节点就好了
    TreeNode* pre =NULL;
    bool isValidBST_V2(TreeNode* root){
        if(root==NULL) return true;
        bool left =isValidBST_V2(root->left);
        if(pre!=NULL && pre->val>=root->val) return false;
        pre =root;

        bool right = isValidBST_V2(root->right);
        return left && right;
    }
    // 迭代法，也是留一个pre指针的思路，用中序遍历迭代法去访问元素即可。
    bool isValidBST_V3(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while(cur!=NULL ||!st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur =cur->left;
            }
            else{
                cur =st.top();
                st.pop();
                if(pre!=NULL &&pre->val>=cur->val) return false;
                pre =cur;
                cur =cur->right;
            }
        }
        return true;
    }
};
