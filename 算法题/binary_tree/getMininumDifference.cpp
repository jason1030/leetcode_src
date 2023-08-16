# include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Recursion{
private:
    int result = INT_MAX;
    TreeNode* pre =NULL;
    void traversal(TreeNode* cur){
        if(cur ==NULL) return ;
        traversal(cur->left);
        if(pre!=NULL){
            result = min(result, cur->val - pre->val);
        }
        pre =cur;
        traversal(cur->right);
    }
    
public:
    int getMininumDiff(TreeNode* root){
        traversal(root);
        return result;
    }
};

class Iteration{
public:
    int getMininumDiff(TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* cur =root;
        TreeNode* pre =NULL;
        int result = INT_MAX;
        // 迭代法的中序遍历中，访问顺序（进栈）和处理顺序（左中右）是不一样的。
        while(cur!=NULL ||!st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur =st.top();
                st.pop();
                if(pre!=NULL){
                    result =min(result, cur->val -pre->val);
                    pre = cur;
                    cur = cur->right;
                }
            }
        }
        return result;
        
    }
};