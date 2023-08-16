// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem455.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
// #include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() -1;
        int result = 0;
        for(int i = g.size()-1; i>=0; i--){
            if(index>=0 && s[index]>=g[i]){
                result++;
                index--;
            }
        }
        return result;
    }
};
// @lc code=end

