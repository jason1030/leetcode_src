#include<vector>
#include<string>

using namespace std;

class solution{
private:
    // 构建数字与字母的映射表
    const string letterMap[10] ={
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index){
        // 终止条件：当下标等于输入数字列长度时，返回到result
        if(index==digits.size()){
            result.push_back(s);
            return;
        }
        // 先得到当前下标对应数字
        int digit = digits[index]- '0';
        // 找到映射的字母集合（字母串）
        string letters = letterMap[digit];
        // for横向循环处理当前字符集
        for(int i =0;i<letters.size();i++){
            s.push_back(letters[i]); //处理
            backtracking(digits, index + 1);// 递归，注意index+1,处理下一层数字
            s.pop_back();//回溯
        }

    vector<string> letterCombination(string digits){
        s.clear();
        result.clear();
        if(digits.size()==0) return result;
        backtracking(digits, 0);
        return result;
    }
        

    }
};