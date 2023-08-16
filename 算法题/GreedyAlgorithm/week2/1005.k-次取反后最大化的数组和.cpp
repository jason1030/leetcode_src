/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {

public:
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // step1:先按绝对值从大到小进行排序
        sort(nums.begin(), nums.end(), cmp);
        // 2.筛选出绝对值大的负数，将其变为正数
        for(int i =0; i< nums.size(); i++){
            if(nums[i] <0 && k >0){
                nums[i] *= -1;
                k--;
            }
        }
        // 3.如果k还有余，就全部用于最小的正数（奇数次变为负数）
        if(k % 2 ==1) nums[nums.size()-1] *= -1;
        int res = 0;
        // 4.求和
        for(int num:nums) res += num; 
        return res;

    }
};
// @lc code=end

