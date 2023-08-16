#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 层序遍历：使用队列来保存访问的节点，然后按序输出即可
class solution{
public:
    vector<vector<int>> levelOrderTraversal(TreeNode* root){
        queue<TreeNode*> treeQue;
        if(root!=NULL) treeQue.push(root);
        vector<vector<int>> result;
        while(!treeQue.empty()){
            //注意用固定size，因为队列的size一直在变
            int size =treeQue.size();
            vector<int> vec;
            for(int i =0;i<size;i++){
                TreeNode* node = treeQue.front();
                treeQue.pop();
                vec.push_back(node->val);
                if(node->left) treeQue.push(node->left);
                if(node->right) treeQue.push(node->right);
            }
            result.push_back(vec);
        }
        
        return result;
    }    
};
