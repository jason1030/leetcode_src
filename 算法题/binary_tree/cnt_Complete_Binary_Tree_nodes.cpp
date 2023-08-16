using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


/*  这里利用好完全二叉树的一些特性可以提高计算效率  
    完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满。
    对于情况一，可以直接用 2^树深度 - 1 来计算，注意这里根节点深度为1。
    对于情况二，分别递归左孩子，和右孩子，递归到某一深度一定会有左孩子或者右孩子为满二叉树，然后依然可以按照情况1来计算。*/
class solution{
public:
    int CountNodesCBT(TreeNode* root){
        if(root==nullptr) return 0;
        TreeNode* left =root->left;
        TreeNode* right = root->right;
        int leftDepth =0, rightDepth =0;
        while(left){
            left = left->left;
            leftDepth++;
        }
        while(right){
            right =right->right;
            rightDepth++;
        }
        // 注意2<<n 等价于2^(n+1)，这也是为什么深度从0开始计算
        if(leftDepth==rightDepth){
            return (2<<leftDepth)-1;
        }

        return CountNodesCBT(root->left) + CountNodesCBT(root->right)+1;
        
    }
};