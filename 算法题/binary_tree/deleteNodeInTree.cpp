#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class BST{
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        // 终止条件：为空，说明没找到节点，直接返回
        if(root==NULL) return root;
        // 找到节点有四种情况，一一处理
        if(root->val ==key){
            //case 1: 左右子树均为空，直接删除当前节点，返回空节点即可
            if(root->left==NULL && root->right==NULL){
                delete root;
                return nullptr;
            }
            // case 2:左子树为空，删除当前节点，然后返回右子树根节点作为新的根节点
            else if(root->left==NULL){
                auto retNode = root->right;
                delete root;
                return retNode;
            }
            // case 3: 同上，删除当前节点，返回左子树根节点作为新的根节点
            else if(root->right==NULL){
                auto retNode = root->left;
                delete root;
                return retNode;
            }
            // case 4: 左右子树都不为空，那就将左子树接到右子树最左节点的左孩子位置，删除当前节点，并将右孩子根节点作为新的根节点
            else {
                TreeNode* cur = root->right;
                while(cur->left!=nullptr){
                    cur =cur->left;
                }
                TreeNode* tmp = root;
                cur->left =root->left;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if(root->val >key) root->left =deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
     }

};


class normal{
public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root ==nullptr) return root;
        if(root->val ==key){
            if(root->right==nullptr) return root->left;
            TreeNode* cur =root->right;
            while(cur->left){
                cur = cur->left;
            }

            swap(root->val, cur->val);
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    } 
};


class iterarion{
private:
    // 当前节点cur的值为target时，给出删除方法
    TreeNode* deleteOneNode(TreeNode* target){
        if(target == nullptr) return target;
        if(target->right ==nullptr) return target->left;
        TreeNode* cur =target->right;
        while(cur->left){
            cur = cur->left;
        }
        cur->left = target->left;
        return target->right;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == nullptr) return root;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        // 迭代正常遍历，找到符合的节点
        while(cur){
            if(cur->val == key) break;
            pre = cur;
            if(cur->val> key) cur = cur->left;
            else cur= cur->right;
        } 
        // case 1:只有当前一个节点，直接删
        if(pre==nullptr) return deleteOneNode(cur);
        // 根据pre 来了解 要删左孩子还是右孩子
        // case2：左孩子
        if(pre->left && pre->left->val==key){
            pre->left =deleteOneNode(cur);
        } 
        // case3; 右孩子
        if(pre->right && pre->right->val==key){
            pre->right = deleteOneNode(cur);
        }
        return root;
    }
};