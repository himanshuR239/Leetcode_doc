class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(int ind, int prev_idx, vector<int>& nums){
        if(ind == n) return 0;

        if(dp[ind][prev_idx+1] != -1) return dp[ind][prev_idx+1];

        int len = solve(ind+1, prev_idx, nums);

        if(prev_idx == -1 || nums[prev_idx] < nums[ind]){
            len = max(len, 1 + solve(ind+1, ind, nums));
        }

        return dp[ind][prev_idx+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, nums);
    }
};