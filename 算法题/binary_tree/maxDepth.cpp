# include <queue>
# include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class solution{
public: 
    // 递归法后序遍历，先得到左右子树的最大深度，然后再+1
    int GetDepthPostorder(TreeNode* node){
        if(node ==nullptr) return 0;
        int leftdepth =GetDepthPostorder(node->left);
        int rightdepth =GetDepthPostorder(node->right);
        int depth = 1 + max(leftdepth, rightdepth);

    }



    int MaxDepthRecursionPostorder(TreeNode* root){
        return GetDepthPostorder(root);
    }

    // 递归法先序遍历，更符合遍历的格式，先访问当前节点，然后递归去求得左右子树的深度并更新深度
    int result;
    void GetDepthPreorder(TreeNode* node, int depth){
        result = depth>result?depth:result;

        if(node->left==NULL && node->right==NULL) return;
        if(node->left){
            depth++;
            GetDepthPreorder(node->left, depth);
            depth--;
        }
        if(node->right){
            depth++;
            GetDepthPreorder(node->right, depth);
            depth--;
        }
        return ;


    }


    int MaxDepthRecursionPreorder(TreeNode* root){
        result =0;
        if(root==nullptr) return result;
        GetDepthPreorder(root, 1);
        return result;

    }
    
    // 层次遍历法：这个其实是解释性最好的，每遍历一层就增加一层深度
    int MaxDepthLevel(TreeNode* root){
        if(root==nullptr) return 0;
        int depth =0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size =que.size();
            depth++;
            for(int i =0;i<size;i++){
                TreeNode* cur =que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return depth;

    }

};