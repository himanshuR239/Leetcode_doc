class Solution {
public:
    int n;
    int dp[300][1001][11];
    int solve(int ind, int maxi, int d, vector<int>& jobDifficulty){
        if(ind == n && d == 0) return maxi;
        if(ind == n) return 1e9;
        if(d<0) return 1e9;

        if(dp[ind][maxi][d] != -1) return dp[ind][maxi][d];
  
        int take = solve(ind+1, max(maxi, jobDifficulty[ind]), d, jobDifficulty);

        int skip = 1e9;
        if(d >= 1) skip = maxi + solve(ind+1, jobDifficulty[ind], d-1, jobDifficulty);

        return dp[ind][maxi][d] = min(take, skip);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();

        if(n < d) return -1;

        memset(dp, -1, sizeof(dp));
        return solve(1, jobDifficulty[0], d-1, jobDifficulty);
    }
};