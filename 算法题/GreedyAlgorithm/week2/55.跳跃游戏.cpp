/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size()==1) return true;
        // 注意这里的边界是cover，表示能跳跃到的范围，随着循环进行cover也在不断更新
        for(int i = 0; i <= cover; i++){
            cover = max(i + nums[i], cover);
            if(cover >= nums.size() -1) return true;
        }

        return false;

    }
};
// @lc code=end

