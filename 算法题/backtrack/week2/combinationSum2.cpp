# include<vector>
# include<algorithm>

using namespace std;
// 这道题目和39.组合总和如下区别：
// 本题candidates 中的每个数字在每个组合中只能使用一次。
// 本题数组candidates的元素是有重复的，
// 而39.组合总和是无重复元素的数组candidates
class solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used){
        if(sum>target){
            return;
        }
        
        if(sum==target){
            result.push_back(path);
            return;
        }

        for(int i =startIndex; i<candidates.size(); i++){
            // 多加入了bool型数组used,用以记录同一树枝上的元素是否使用过，来达到去重的效果
            // 在candidates[i] == candidates[i - 1]时，
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过,因为这说明candidate[i]是从candidate[i-1]回溯过来的
            if(i>0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            path.push_back(candidates[i]);
            sum +=candidates[i];
            used[i] == true;
            // 进入下一层递归
            backtracking(candidates, target, sum, i, used);
            // 回溯，这里有三个操作：将used[i]修改为false, 从path中弹出元素，sum减去当前元素，然后开始遍历树层中下一个元素
            used[i] == false;
            path.pop_back();
            sum -=candidates[i];
        }
    }


public:
    vector<vector<int>> combinationSum2(vector<int> candidates, int target){
        vector<bool> used(candidates.size(), false);
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }

};