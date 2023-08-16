# include <iostream>
# include <vector>
# include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){} 
};

TreeNode* construct_binary_tree(const vector<int>& vec){
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    
    for(int i =0;i<vec.size();i++){
        TreeNode* node =NULL;
        if(vec[i]!= -1) node = new TreeNode(vec[i]);
        vecTree[i] =node;
        if(i ==0) root = node;
    }

    for(int i =0; i*2 +1<vec.size();i++){
        if(vecTree[i]!= NULL){
            vecTree[i]->left =vecTree[i*2 +1];
            if(i*2 +2<vec.size())
            vecTree[i]->right = vecTree[i*2+2];

        }
    }
    return root;
}

void print_binary_tree(TreeNode* root){
    queue<TreeNode*> que;
    if(root!=NULL) que.push(root);
    vector<vector<int>> result;
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i =0; i<size;i++){
            TreeNode* node =que.front();
            que.pop();
            if(node!=NULL){
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);             
            }
            else vec.push_back(-1);
        }
        result.push_back(vec);
        
    }

    for(int i =0;i< result.size();i++){
        for(int j =0;j<result[i].size();j++)
        {   if(result[i][j]!=-1)cout << result[i][j] <<" ";
            else cout << "NULL"<<" ";
        }
        cout<<endl;
    }
}

int main() {
    // 注意本代码没有考虑输入异常数据的情况
    // 用 -1 来表示null
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = construct_binary_tree(vec);
    print_binary_tree(root);
}