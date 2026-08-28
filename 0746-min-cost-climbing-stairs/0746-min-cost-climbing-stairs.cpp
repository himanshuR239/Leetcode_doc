class Solution {
public:
    int n;
    int dp[1000];
    int solve(int ind, vector<int>& cost){
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];

        int one = cost[ind] + solve(ind+1, cost);
        int two = cost[ind] + solve(ind+2, cost);

        return dp[ind] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost), solve(1, cost));
    }
};