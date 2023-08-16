#include <queue>
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};


class solution{
public:
    //递归法：确定好三要素：参数和返回值，临界条件，处理单元。
    bool compare(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode==nullptr && rightNode==nullptr) return true;
        else if(leftNode!=NULL && rightNode==NULL) return false;
        else if(leftNode==NULL && rightNode!=NULL) return false;
        else if(leftNode->val!=rightNode->val) return false;
        else return compare(leftNode->left,rightNode->right)&& compare(leftNode->right, rightNode->left);
    }        

    bool isSymmetricRecursion(TreeNode* root){
        if(root== NULL) return true;
        return compare(root->left, root->right);
    }


    // 迭代法：用一个队列存储遍历序列就可以了，先访问根节点的左右子节点，然后依次将左左，右右，左右，右左加入队尾
    // 每次从对首取出一对节点进行比较，如此进行
    // 注意用stack存储序列也是可以的，实现上基本相同
    bool isSymmetricIterQueue(TreeNode* root){
        if(root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* leftNode =que.front();
            que.pop();
            TreeNode* rightNode =que.front();
            que.pop();
            if(!leftNode && !rightNode) continue;

            if(!leftNode||!rightNode||leftNode->val!=rightNode->val) return false;

            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);

        }
        return true;
        
    }



};