# include <vector>
# include <string>

using namespace std;
class solution {
private:
    vector<vector<string>> result;

    void backtracking (int n, int row, vector<string>& chessboard) {
        if(row == n){
            result.push_back(chessboard);
            return;
        }

        for(int col =0; col < n; col++){
            if(isValid(row, col, chessboard, n)){
                chessboard[row][col] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }
    // 检查是否满足放置条件
    // 因为是自上而下去遍历的，所以只需要看上方的棋子是否与该点同行同列同斜线
    // 在单层搜索的过程中，每一层递归，只会选for循环（也就是同一行）里的一个元素，所以不用去检查同行的元素
    bool isValid(int row, int col, vector<string>& chessborad, int n){
        //  同列
        for(int i= 0; i<row; i++){
            if(chessborad[i][col] == 'Q') return false;
        }
        // 45度
        for(int i  = row -1, j = col -1; i>=0 && j >=0; i--, j--){
            if(chessborad[i][j] == 'Q') return false;
            
        } 
        // 135度
        for(int i = row -1, j = col +1; i>=0 && j<n; i--, j++){
            if(chessborad[i][j] == 'Q') return false;
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n){
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }

};