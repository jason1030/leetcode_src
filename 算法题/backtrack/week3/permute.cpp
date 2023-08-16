#include <vector>

using namespace std;

class solution{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, vector<bool>& used){
        // 终止条件：收集叶子节点，当path与nums一样大的时候回收其中的元素
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        // 排列问题与组合/分割问题最大的不同点在于：排列问题每次都要从头开始搜索，所以循环的起始Index是0，不需要startindex作为标记
        for(int i = 0; i< nums.size(); i++){
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }


public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<bool> used(nums.size(), false);
        path.clear();
        result.clear();
        backtracking(nums, used);
        return result;
    }
};