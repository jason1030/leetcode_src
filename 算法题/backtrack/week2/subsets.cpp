# include<vector>
# include<string>
// 该题为子集问题，不同于组合or分割问题，如果把 子集问题、组合问题、分割问题都抽象为一棵树的话，
// 那么组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点
using namespace std;
class solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& nums, int startIndex){
        // 因为每个节点都要收集，所以对path的回收要在临界点判别之前
        // 如果是收集叶子节点就是在临界判别内收集
        result.push_back(path);
        if(startIndex >= nums.size()){
            return;
        }

        for(int i = startIndex; i<nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> nums){
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }

    

};