# include<iostream>
# include<unordered_map>
# include<vector>
# include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
// 普通二叉树，就遵循正常的遍历过程去查找，用map记录每个值出现频率，找到最高的输出
class normalBT{
private:
    void searchBT(TreeNode* cur, unordered_map<int, int>& map){
        if(cur ==NULL) return ;
        map[cur->val]++;
        searchBT(cur->left, map);
        searchBT(cur->right, map);
        return ;
    }

    bool static cmp(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }

public:
    vector<int> findMode(TreeNode* root){
        unordered_map<int, int> map;
        vector<int> result;
        if(root==NULL) return result;
        searchBT(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        result.push_back(vec[0].first);
        for(int i =1;i<vec.size();i++){
            if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
        }
        
        return result;        
    }
};

// 二叉搜索树，中序遍历下本身就是有序的，那么就可以边遍历边计数，统计到最大的count就放入result中
class BST{
private:
    int maxCnt =0;
    int cnt =0;
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur){
        if(cur == NULL) return;
        // 左
        searchBST(cur->left);

        // 中（处理当前节点）
        if(pre==NULL) cnt=1;
        else if(pre->val == cur->val){
            cnt++;
        } 
        else cnt =1;
        // 等于时当前maxcnt的，加入结果中
        pre = cur;
        if(cnt ==maxCnt) result.push_back(cur->val);
        // 注意，碰到更大的cnt，先清空原result数组，再放目前最大的
        if(cnt>maxCnt){
            maxCnt = cnt;
            result.clear();
            result.push_back(cur->val);
        }
        // 右
        searchBST(cur->right);
        return ;
    }


public:
    vector<int> findMode(TreeNode* root){
        cnt = 0;
        maxCnt =0;
        pre = NULL;
        result.clear();

        searchBST(root);
        return result;
    }
};