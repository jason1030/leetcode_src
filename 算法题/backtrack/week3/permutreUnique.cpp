// 该题是全排列2
#include <vector>
#include <algorithm>

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
            // 与全排列1不同的是，这题中提供的数组里有重复元素，那么就 涉及到去重问题，这里用used数组来进行去重处理
            // 值得注意的是，这里判别写used[i-1]==true 也是可以的，但false 是从树层上去重，true 是从树枝上去重，前者效率更高
            if(i >0 && nums[i] ==nums[i-1] && used[i-1]==false){
                continue;
            }
            // 这里还是得看当前元素是否被选取过，选过就跳过了
            if(used[i]== false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            } 
        }
    }


public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<bool> used(nums.size(), false);
        path.clear();
        result.clear();
        sort(nums.begin(), nums.end()); //使用used数组就得排序
        backtracking(nums, used);
        return result;
    }
};