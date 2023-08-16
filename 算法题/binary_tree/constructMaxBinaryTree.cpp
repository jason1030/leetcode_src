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


class recuersion{
private:
    TreeNode* traversal(vector<int>& nums, int left, int right){
        if(left>=right) return nullptr;
        
        int maxValueIndex = left;
        for(int i =left+1;i<right;i++){
            if(nums[i]>nums[maxValueIndex]) maxValueIndex =i;
        }
        
        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        root->left = traversal(nums, left, maxValueIndex);
        root->right = traversal(nums, maxValueIndex+1, right);

        return root;
    }
public:
    TreeNode* constructMaxBinaryTree(vector<int>& nums){
        return traversal(nums, 0, nums.size()-1);
    }
    
};