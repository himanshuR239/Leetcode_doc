class Solution {
public:
    int m;
    int n;
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>>& board){
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || board[i][j] == 'X') return;
        vis[i][j] = true;

        dfs(i+1, j, vis, board);
        dfs(i, j+1, vis, board);
        dfs(i-1, j, vis, board);
        dfs(i, j-1, vis, board);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, vis, board);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[i][n-1] == 'O' && !vis[i][n-1]){
                dfs(i, n-1, vis, board);
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, vis, board);
            }
        }
        for(int j = 0; j < n; j++){
            if(board[m-1][j] == 'O' && !vis[m-1][j]){
                dfs(m-1, j, vis, board);
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};