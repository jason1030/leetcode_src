#include<iostream>
#include<vector>
#include<queue>
#include<string>
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
    void traversal(TreeNode* cur, string path, vector<string>& result){
        path +=to_string(cur->val);
        if(cur->left==NULL && cur->right==NULL){
            result.push_back(path);
            return;
        }
        // 注意回溯隐藏在了函数的传参中，这里path 直接是指传递，下一层递归调用traversal函数，函数结束后path值又回到调用前状态（C++特性）
        // 左
        if(cur->left) traversal(cur->left, path + "->", result);
        // 右
        if(cur->right) traversal(cur->right, path + "->", result);

    }


public:
    vector<string> binaryTreePathes(TreeNode* root){
        vector<string> result;
        string path;
        if(root==NULL) return result;
        traversal(root, path, result);
        return result;
    }
};



class iteration{
public:
    vector<string> binaryTreePathes(TreeNode* root){
        // 树节点栈
        stack<TreeNode*> treeSt;
        // 保存路径
        stack<string> pathSt;
        // 最后路径集合
        vector<string> result;

        if(root==NULL) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        
        while(!treeSt.empty()){
            TreeNode* node = treeSt.top(); treeSt.pop();
            string path = pathSt.top(); pathSt.pop();

            if(node->left==NULL && node->right ==NULL){
                result.push_back(path);
            }
            // 注意入栈先右后左保证出栈顺序正确
            if(node->right){
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if(node->left){
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};