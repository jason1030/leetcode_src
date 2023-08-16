/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
# include <vector>
# include <algorithm>
# include "string.h"
# include <iostream>
using namespace std;
// @lc code=start
// 贪心解法
// 贪心只需要统计局部峰值的数量即可，那么解决局部峰值的判断就要考虑全情况
// 主要有三种特殊情况：情况一：上下坡中有平坡 情况二：数组首尾两端 情况三：单调坡中有平坡

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int curdiff = 0;
        int prediff = 0;
        // 针对情况2, 可以假设数组前还有一个数字，这样即使两个不同数字组成的数组也能正确统计
        int result = 1;
        for(int i = 0; i< nums.size()-1; i++){
            curdiff = nums[i+1] - nums[i];
            // 针对情况一，只需要统一统计平坡的左端点或者右端点即可，这里统计右端点，即prediff可以为0
            // 针对情况三，在坡度发生变化时才对prediff更新，这样情况三就不会算作峰值产生
            if((prediff <= 0 && curdiff > 0)||(prediff >= 0 && curdiff < 0)){
                result ++;
                prediff = curdiff;
            }
        }
        
        return result;

    }
};
// 动态规划解法
class Solution{
public:
    int wiggleMaxLength(vector<int>& nums){
        // dp[i][0]表示第i个数作为山峰的摆动子序列 的最长长度
        // dp[i][1]表示第i个数作为山谷的摆动子序列 的最长长度
        // 
        int dp[1005][2];
        memset(dp, 0, sizeof dp);

        dp[0][0] = dp[0][1]  =1;
        for (int i = 1; i < nums.size(); ++i){
            dp[i][0] = dp[i][1]  =1;
            // 通过两个循环来维护dp数组的状态
            for (int j =0 ; j < i ; ++j){
                // 表示将 nums[i]接到前面某个山峰后边，作为山谷
                if(nums[j] > nums[i]) dp[i][1] = max(dp[j][0]+1, dp[i][1]);                
            }
                // 表示将 nums[i]接到前面某个山谷后面，作为山峰
            for(int j =0 ; j<i; ++j){
                if(nums[j] < nums[i]) dp[i][0] = max(dp[j][1]+1, dp[i][0]);                
                
            }
        }
        return max(dp[nums.size() -1][0], dp[nums.size() -1][1]);
    }
};
// @lc code=end

