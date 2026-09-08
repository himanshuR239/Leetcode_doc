class Solution {
public:
    int n;
    int dp[21][2005];
    int offset = 1000;
    int solve(int ind, int target, vector<int>& nums){
        if(ind == n && target == 0) return 1;
        if(ind >= n) return 0;

        if(target < -1000 || target > 1000) return 0;

        if(dp[ind][target+offset] != -1) return dp[ind][target+offset];

        int plus = solve(ind+1, target - nums[ind], nums);
        int minus = solve(ind+1, target + nums[ind], nums);

        return dp[ind][target+offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, target, nums);
    }
};