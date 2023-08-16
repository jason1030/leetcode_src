#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

// 递归法
class recursion{
private:
    TreeNode* traversal(vector<int>& nums, int left, int right){
        // 终止条件：左下标大于右下标（因为是闭区间）
        if(left>right) return nullptr;
        // 求出中间下标作为当前根节点值
        int mid = left +((right-left)/2);
        TreeNode* root = new TreeNode(nums[mid]);
        // 递归处理左子树
        root ->left = traversal(nums, left, mid-1);
        // 递归处理右子树
        root ->right = traversal(nums, mid+1, right);
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        TreeNode* root  = traversal(nums, 0, nums.size()-1);
        return root;
    }
};
// 迭代法
class iteration{
    TreeNode* sortedArrayTodBST(vector<int>& nums){
        if(nums.size()==0) return nullptr;
        
        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> nodeQue; //放遍历节点
        queue<int> leftQue; // 左区间下标
        queue<int> rightQue; //右区间下标
        // 根节点入队，0作为初始左下标，nums.size() -1作为初始右下标
        nodeQue.push(root);
        leftQue.push(0);
        rightQue.push(nums.size()-1);

        while(!nodeQue.empty()){
            TreeNode* curNode = nodeQue.front();
            nodeQue.pop();
            int left = leftQue.front(); leftQue.pop();
            int right = rightQue.front(); rightQue.pop();

            int mid  = left + ((right - left)/2);
            // mid元素给中间节点
            curNode ->val  = nums[mid];

            if(left<= mid -1){  //处理左区间
                curNode->left = new TreeNode(0);
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid-1);
            }

            if(right>= mid +1){ //处理右区间
                curNode->right = new TreeNode(0);
                nodeQue.push(curNode->right);
                leftQue.push(mid+1);
                rightQue.push(right);
            }

    
        }
        return root;
    }
    
    
};