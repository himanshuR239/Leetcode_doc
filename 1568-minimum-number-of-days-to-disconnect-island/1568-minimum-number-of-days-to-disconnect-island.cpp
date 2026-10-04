class Solution {
public:
    int m, n;
    void dfs(int r, int c, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        if(r >= m || r < 0 || c >= n || c < 0 || vis[r][c] || grid[r][c] == 0) return;

        vis[r][c] = 1;
        dfs(r+1, c, vis, grid);
        dfs(r, c+1, vis, grid);
        dfs(r-1, c, vis, grid);
        dfs(r, c-1, vis, grid);
    }

    int count(vector<vector<int>>& grid){
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(count(grid) != 1) return 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;

                    if(count(grid) != 1) return 1;

                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};