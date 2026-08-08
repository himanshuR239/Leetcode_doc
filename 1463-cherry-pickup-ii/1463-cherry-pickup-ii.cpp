class Solution {
public:
    int m;
    int n;

    int dp[70][70][70];

    bool isValid(int i, int j1, int j2){
        if(i >= 0 && i < m && j1 >= 0 && j1 < n && j2 >= 0 && j2 < n) return true;
        return false;
    }

    int solve(int i, int j1, int j2, vector<vector<int>>& grid){
        if(!isValid(i, j1, j2)) return -1e9;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int cherry = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

        if(i == m-1) return cherry;

        int maxi = 0;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                maxi = max(maxi, solve(i+1, j1 + dj1, j2 + dj2, grid));
            }
        }

        return dp[i][j1][j2] = cherry + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        // {i, j1, j2}
        return solve(0, 0, n-1, grid);
    }
};