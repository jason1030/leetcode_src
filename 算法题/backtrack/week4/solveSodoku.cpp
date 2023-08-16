# include <vector>
# include <string>

using namespace std;
class solution {
private:
bool backtracking(vector<vector<char>>& board){
    // 与前面递归回溯问题不同的事，这是二维递归，复杂度会高一些
    // Q皇后看似是二维递归问题，但因为每行只能放一个棋子，所以简化为一维递归问题
    for(int i=0; i<board.size(); i++){
        for(int j =0; j<board[0].size(); j++){
            if(board[i][j] == '.'){
                for(char k = '1'; k<= '9'; k++){
                    if(isValid(i, j, k, board)){
                        board[i][j] = k;
                        if(backtracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                // 这里false的作用是，尝试九个数都不行的话，说明这个棋盘找不到解决数独问题的解
                return false;
            }
        }
    }
    return true;
}


bool isValid(int row, int col, char val, vector<vector<char>>& board){
    // 检查列
    for(int i =0;  i< 9; i++){
        if(board[i][col] == val) return false;
    }
    // 检查行
    for(int j = 0; j<9; j++){
        if(board[row][j] == val) return false;
    }
    // 检查所在九宫格
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i =startRow; i< startRow +3; i++){
        for(int j = startCol; j< startCol +3; j++){
            if(board[i][j] == val) return false;
        }
    }
    return true;
}

public:
    void solveSodoku(vector<vector<char>>& board){
        backtracking(board);
    }

};