class Solution {
public:
    void helper(int col, int row, vector<string> &cur, int n, bool place){
        cur[row][col] = place ? 'Q' : '.';
    }

    bool isSafe(int col, int row, vector<string> &cur, int n){
        for(int i = 0; i < row; i++){
            if(cur[i][col] == 'Q') return false;
        }

        for(int i = row-1, j = col -1; i >= 0 && j >= 0; i--, j--){
            if(cur[i][j] == 'Q') return false;
        }

        for(int i = row-1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(cur[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, vector<string> &cur, int n, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < n; i++){
            if(isSafe(i, row, cur, n)){
                helper(i, row, cur, n, true);
                solve(row+1, cur, n, ans);
                helper(i, row, cur, n, false);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));

        solve(0, cur, n, ans);

        return ans;
    }
};