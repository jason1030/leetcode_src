# include <vector>
# include <map>
# include <unordered_map>
# include <string>
using namespace std;


class solution {
private:
// 这里关于数据结构的选取：由于一个起点会映射到多个终点，所以要使key有序的，要么map , multimap, 或者multiset
// 但是由于起点终点可能会有重复的，搜索过程中没及时删除已经到达过的目的机场，就会出现回环（不是合理的路径）
// 所以这里选取map，通过修改value来达到增删的效果，当value等于0 时，表示目的地已经到达过了，不能收集到路径中
// 含义如下：unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    // 因为这里要求是搜素到一条符合条件的路径且这个路径唯一，那么这里递归函数是需要返回值的，遇到符合条件的路径就得及时返回
    bool backtracking(int ticketNum, vector<string>& result){
        // 当路径节点个数==航班数 +1 时，说明把所有航班整合到一条路径里了，这时可以返回了
        if(result.size()== ticketNum + 1){
            return true;
        }
        
        for(pair<const string, int>& target : targets[result[result.size()-1]]){
            if(target.second > 0){
                result.push_back(target.first);
                target.second --;
                if(backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second ++;
            }
        }

        return false;
    }


public:
    vector<string> findItnerary(vector<vector<string>>& tickets){
        targets.clear();
        vector<string>  result;
        // 对targets进行初始化，记录所有的映射关系
        for(const vector<string>& ticket: tickets ){
            targets[ticket[0]][ticket[1]]++;
        }
        // result初始化，起点为"JFK"
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};