class Solution {
public:
    int n;
    int MOD = 1e9+7;
    int dp[100001][3][4];

    int solve(int ind, int last_par, int k, vector<int>& nums){
        if(k == 0) return 0;
        if(ind >= n) return 1;

        if(dp[ind][last_par+1][k] != -1) return dp[ind][last_par+1][k];

        int notTake = solve(ind+1, last_par, k, nums);

        int take = 0;
        int cur_par = nums[ind] % 2;
        if(cur_par == last_par){
            take = solve(ind+1, cur_par, k-1, nums) % MOD;
        }
        else{
            take = solve(ind+1, cur_par, 2, nums) % MOD;
        }

        return dp[ind][last_par+1][k] = (take + notTake) % MOD;
    }
    int countStableSubsequences(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, 3, nums) - 1;
    }
};