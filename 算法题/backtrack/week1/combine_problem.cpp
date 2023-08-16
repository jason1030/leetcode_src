#include<vector>

using namespace std;
class solution{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size()==k){ //找到终止条件
            result.push_back(path);//存放结果
            return;
        }
        // 这里可以剪枝，已选择元素有pach.size()个，那么还需要k-path.size()个，在集合n中至多起始位置则为n- (k-path.size())+1，大于这个的就不符合条件可以不用继续遍历了
        for(int i=startIndex; i<=n- (k-path.size())+1; i++){//横向遍历
            path.push_back(i);//处理节点
            backtracking(n, k, i+1);//递归，纵向遍历
            path.pop_back();//回溯，撤销处理的节点
        }
        
    }


public:
    vector<vector<int>> combine(int n, int k){
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }


};