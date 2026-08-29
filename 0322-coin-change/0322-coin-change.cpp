class Solution {
public:
    int n;
    int dp[13][10001];
    int solve(int ind, vector<int>& coins, int amount){
        if(ind >= n) return 1e9;

        if(amount == 0) return 0;

        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = solve(ind+1, coins, amount);
        int take = INT_MAX;
        if(coins[ind] <= amount){
            take = 1 + solve(ind, coins, amount - coins[ind]);
        }

        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, coins, amount);
        return ans == 1e9 ? -1 : ans;
    }
};