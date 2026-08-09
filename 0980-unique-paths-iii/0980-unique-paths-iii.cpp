class Solution {
public:
    int m;
    int n;
    int ans = 0;
    int empty = 0;

    void dfs(int x, int y, vector<vector<int>>& grid, int cnt){
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1) return;

        if(grid[x][y] == 2){
            if(cnt == empty) ans++;
        }

        int temp = grid[x][y];
        grid[x][y] = -1;

        dfs(x+1, y, grid, cnt+1);
        dfs(x-1, y, grid, cnt+1);
        dfs(x, y+1, grid, cnt+1);
        dfs(x, y-1, grid, cnt+1);

        grid[x][y] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int x = -1;
        int y = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 || grid[i][j] == 0){
                    empty++;
                }
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
            }
        }

        dfs(x, y, grid, 0);

        return ans;
    }
};