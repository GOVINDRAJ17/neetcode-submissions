class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<bool> cols;
    vector<bool> diag1;
    vector<bool> diag2;

    void backtrack(int row,int n){
        if(row==n){
            result.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(cols[col])
                continue;
            if(diag1[row-col+n-1])
                continue;
            if(diag2[row+col])
                continue;

            board[row][col]='Q';
            cols[col]=true;
            diag1[row-col+n-1]=true;
            diag2[row+col]=true;

            backtrack(row+1,n);
            
            board[row][col]='.';
            cols[col]=false;
            diag1[row-col+n-1]=false;
            diag2[row+col]=false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        cols = vector<bool>(n, false);

        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        backtrack(0, n);

        return result;
    }
};
