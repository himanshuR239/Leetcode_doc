class Solution {
public:
    int m;
    int n;
    void dfs(int r, int c, vector<vector<char>>& grid){
        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;

        grid[r][c] = '0';

        dfs(r+1, c, grid);
        dfs(r-1, c, grid);
        dfs(r, c+1, grid);
        dfs(r, c-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }
};