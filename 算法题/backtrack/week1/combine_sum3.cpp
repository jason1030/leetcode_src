#include<vector>

using namespace std;

class solution{
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k ,int sum, int startIndex){
        // 剪枝1：和大于targetSum直接结束
        if(sum > targetSum){
            return;
        }
        
        if(path.size()==k){
            if(sum == targetSum) result.push_back(path);
            return;
        }
        // 剪枝2：循环下标范围 i<=9 -(k - path.size())+1
        for(int i = startIndex; i<=9 -(k - path.size())+1; i++){
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(int k, int n){
        result.clear();
        path.clear();
        backtracking(n, k, 0, 1);
        return result;
    }
    
};