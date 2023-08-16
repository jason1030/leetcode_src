#include <vector>
#include <algorithm>

using namespace std;

class soluiton{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> nums, int startIndex, vector<bool>& used){
        result.push_back(path);
        if(startIndex>=nums.size()){
            return;
        }
        // 本题也可以不使用used数组来去重，因为递归的时候下一个startIndex是i+1而不是0。
        // 如果要是全排列的话，每次要从0开始遍历，为了跳过已入栈的元素，需要使用used。
        for(int i = startIndex; i<nums.size();i++){
            if(i >0 && nums[i]== nums[i-1] && used[i-1]==false){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1, used);
            used[i] = false;
            path.pop_back();

            
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());//去重需要排序
        backtracking(nums, 0, used);
        return result;
        
    }

};