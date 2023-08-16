#include<string>
#include<vector>

using namespace std;

class solution {
private:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string& s, int start, int end){
        for(int i = start, j=end; i<j; i++, j--){
            if(s[i]!=s[j]){
                return false;
            }
        }

        return true;
    }

    void backtracking(const string& s, int startIndex){
        
        if(startIndex>=s.size()){
            result.push_back(path);
            return;
        }

        for(int i = startIndex; i<s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i- startIndex +1);
                path.push_back(str);
            }
            else{
                continue;
            }
            // 当前i是包含进去的，所以从i+1开始继续递归
            backtracking(s, i+1);
            path.pop_back();
        }
    }


public:
    vector<vector<string>> partitionPalindrome(string s){
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }

};