# include <vector>
# include <unordered_set>
using namespace std;

class solution{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size()>1){
            result.push_back(path);
        }
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if((!path.empty() && path.back() > nums.[i] ) || uset.find(nums[i])!= uset.end()){
                continue;
            }
            
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    



public:
    vector<vector<int>> findSubSequences(vector<int>& nums){
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};