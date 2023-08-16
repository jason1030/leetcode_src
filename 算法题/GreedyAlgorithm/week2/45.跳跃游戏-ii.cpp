/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int curDistance = 0;
        int nextDistance = 0;
        int ans = 0;
        for(int i=0; i< nums.size()-1; i++){
            nextDistance =max(i + nums[i], nextDistance);
            if(i == curDistance){
                curDistance = nextDistance;
                ans++;
            }
        }
        return ans;

    }
};
// @lc code=end

