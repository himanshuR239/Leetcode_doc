class Solution {
public:
    int n;
    int dp[201][20001];
    bool solve(int ind, int sum, vector<int>& nums){
        if(sum == 0) return true;
        if(ind == n-1) return nums[ind] == sum;
        
        if(dp[ind][sum] != -1) return dp[ind][sum];

        bool notTake = solve(ind+1, sum, nums);
        bool take = false;
        if(sum >= nums[ind]) take = solve(ind+1, sum-nums[ind], nums);

        return dp[ind][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int tot = 0;
        for(int num : nums) tot += num;
        if(tot % 2 == 1) return false;

        memset(dp, -1, sizeof(dp));
        return solve(0, tot/2, nums);
    }
};