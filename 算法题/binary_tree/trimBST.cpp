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
    TreeNode* trimBST(TreeNode* root, int low, int high){
        // 终止条件：为空就直接返回nullptr
        if(root == nullptr) return nullptr;
        // 注意这里有返回值操作，通过上一层节点来接住这个符合条件的返回值，实现对不符合条件节点的删除
        // 根节点小于low，直接去处理右子树
        if(root->val < low){
            TreeNode* right = trimBST(root->right, low, high);
            return right;
        }
        // 根节点大于high,处理左子树
        if(root->val >high){
            TreeNode* left = trimBST(root->left, low, high);
            return left;
        }
        // 根节点oK,递归处理左右子树
        root->left =trimBST(root->left, low, high);
        root->right =trimBST(root->right, low, high);
        return root;
    }
};

class iteration{
public:
    TreeNode* trimBST(TreeNode* root, int low, int high){
        if(root==nullptr) return nullptr;
        // 先让root确定在区间内
        while(root!=nullptr && (root->val<low || root->val>high)){
            if(root->val<low) root =root->right;
            else root = root->left;
        }

        TreeNode* cur = root;
        // 修建左子树，只看小于low的节点，然后把当前节点和左子树一并修建掉即可
        while(cur!=nullptr){
            while(cur->left && cur->left->val<low){
                cur->left =cur ->left->right;
            }
            cur =cur->left;
        }
        // 同理处理右子树，只看大于high的节点，然后将当前节点和右子树修建掉
        cur =root;
        while(cur!=nullptr){
            while(cur->right && cur->right->val>high){
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};