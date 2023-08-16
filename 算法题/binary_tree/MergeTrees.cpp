# include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class solution{
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
        if(t1==nullptr) return t2;
        if(t2==nullptr) return t1;

        t1->val +=t2->val;
        t1->left= mergeTrees(t1->left, t2->left);
        t1->right =mergeTrees(t1->right, t2->right);
        return t1;
    }


    TreeNode* mergeTreesLevel(TreeNode* t1, TreeNode* t2){
        if(t2==nullptr) return t1;
        if(t1==nullptr) return t2;

        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while(!que.empty()){
            TreeNode* node1 =que.front(); que.pop();
            TreeNode* node2 =que.front(); que.pop();
            node1->val+=node2->val;

            if(node1->left!=nullptr && node2->left!=nullptr){
                que.push(node1->left);
                que.push(node2->left);
            }

            if(node1->right!=nullptr && node2->right!=nullptr){
                que.push(node1->right);
                que.push(node2->right);
            }

            if(node1->left==nullptr && node2->left!=nullptr){
                node1->left =node2->left;
            }
            if(node1->right==nullptr && node2->right!=nullptr){
                node1->right =node2->right;
            }

        }
        
        return t1;
    }
};