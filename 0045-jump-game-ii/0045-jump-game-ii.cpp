class Solution {
public:
    int n;
    int dp[10001];
    int solve(int ind, vector<int> &nums){
        int mini = INT_MAX;

        if(ind >= n-1) return 0;
        if(nums[ind] == 0) return INT_MAX;

        if(dp[ind] != -1) return dp[ind];

        for(int j = 1; j <= nums[ind]; j++){
            int jump = solve(ind+j, nums);

            if(jump != INT_MAX) mini = min(mini, jump+1);
        }

        return dp[ind] = mini;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};