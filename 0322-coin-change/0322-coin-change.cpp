class Solution {
public:
    // int f(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(amount % coins[0] == 0) return amount/coins[0];
    //         else return 1e9;
    //     }
    //     if(dp[ind][amount] != -1) return dp[ind][amount];
    //     int notTake = 0 + f(ind-1, coins, amount, dp);
    //     int take = INT_MAX;
    //     if(coins[ind] <= amount) take = 1 + f(ind, coins, amount-coins[ind], dp);
    //     return dp[ind][amount] = min(notTake, take);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int a=0;a<=amount;a++){
            if(a % coins[0] == 0) dp[0][a] = a/coins[0];
            else dp[0][a] = 1e9;
        }
        for(int ind = 1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int notTake = 0 + dp[ind-1][tar];
                int take = INT_MAX;
                if(coins[ind] <= tar) take = 1 + dp[ind][tar-coins[ind]];
                dp[ind][tar] = min(notTake, take);
            }
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};