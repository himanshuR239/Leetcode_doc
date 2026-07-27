class Solution {
public:
    int m;
    long long helper(int i, vector<vector<int>>& rides, vector<long long> &dp){
        if(i >= m) return 0;

        if(dp[i] != -1) return dp[i];

        long long notTake = helper(i+1, rides, dp);

        vector<int> tar = {rides[i][1], 0, 0};

        int ind = lower_bound(rides.begin()+i+1, rides.end(), tar) - rides.begin();

        long long profit = (long long)rides[i][1] - rides[i][0] + rides[i][2];
        long long take = profit + helper(ind, rides, dp);

        return dp[i] = max(take, notTake);
    } 

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        m = rides.size();

        sort(rides.begin(), rides.end());

        vector<long long> dp(m, -1);
        return helper(0, rides, dp);
    }
};