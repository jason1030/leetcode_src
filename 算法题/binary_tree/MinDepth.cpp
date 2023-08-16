# include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
// 求最小深度，注意要理解清楚题目要求：最小深度是从根节点到最近叶子节点的最短路径上的节点数量
// 所以需要判别当前节点是不是叶子节点，如果只有一边子树，返回子树深度+1，两边都有，再去比较深度更小值
class solution{
    // 递归法后序遍历法
    int GetDepthRecurPost(TreeNode* node){
        if(node==nullptr) return 0;
        int leftDepth = GetDepthRecurPost(node->left);
        int rightDepth = GetDepthRecurPost(node->right);

        if(node->left==nullptr && node->right!=nullptr) return 1+ rightDepth;
        if(node->left!=nullptr && node->right==nullptr) return 1+ leftDepth;

        return 1+ min(leftDepth, rightDepth);
        
    }

    int MinDepthRecurPost(TreeNode* root){
        return GetDepthRecurPost(root);
    }


    //递归法前序遍历法
    int result;
    void GetDepthRecurPre(TreeNode* node, int depth){
        if(node->left==nullptr&& node->right==nullptr) {
            result =min(depth, result);
        }
        if(node->left) GetDepthRecurPre(node->left, depth+1);
        if(node->right) GetDepthRecurPre(node->right, depth+1);

        return;
    }

    int MinDepthRecurPre(TreeNode* root){
        result =__INT_MAX__;
        if(root==nullptr) return 0;
        GetDepthRecurPre(root, 1);
        return result;

    }

    // 迭代法：层序遍历法
    int MinDepthLevel(TreeNode* root){
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
                // 与求最大深度不同，只要在队列中检测到无子树的节点（叶子节点）就直接返回当前深度，即是最小深度
                if(!cur->left && !cur->right) return depth;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return depth;

    }
};