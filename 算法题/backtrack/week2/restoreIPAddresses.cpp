# include<string>
# include<vector>

using namespace std;


class solution {
private:
    vector<string> result;
    
    void backtracking(string& s, int startIndex, int pointNum){
        if(pointNum==3){
            if(isValid(s, startIndex, s.size()-1)){
                result.push_back(s);
            }
        }

        for(int i =startIndex; i<s.size();i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
            }
            pointNum++;
            backtracking(s, i+2, pointNum);
            pointNum--;
            s.erase(s.begin()+i+1);
        }
    }
    
    bool isValid(string& s, int begin, int end){
        // 到末尾了
        if(begin>end) return false;
        // 判别是否有前置0
        if(s[begin]=='0' && begin!=end) return false;
        // 判别数字输入，判别是否大于255
        int tempNum = 0;
        for(int i = begin; i<=end; i++){
            if(s[i]> '9' || s[i] < '0') return false;
            tempNum = tempNum * 10 + (s[i] - '0');
            if(tempNum > 255) return false;

        }

        return true;
    }


public:
    vector<string> restoreIPAddresses(string& s){
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }

};