#include<vector>

using namespace std;

class solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum>target){
            return;
        }

        if(sum ==target){
            result.push_back(path);
            return;
        }
        
        for(int i =startIndex; i<candidates.size();i++){
            path.push_back(candidates[i]);
            sum +=candidates[i];
            backtracking(candidates, target, sum, i); //这里不用i+1表示可以重复选取
            path.pop_back();
            sum -=candidates[i];
        }

    }

public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target){
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};