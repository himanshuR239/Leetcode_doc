class Solution {
public:
    int n;
    int dp[101];
    int solve(int ind, int end, vector<int> &nums){
        if(ind > end) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = nums[ind] + solve(ind + 2, end, nums);
        int skip = solve(ind+1, end, nums);

        return dp[ind] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1) return nums[0];
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(0, n-2, nums);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(1, n-1, nums);

        return max(ans1, ans2);
    }
};