class Solution {
public:
    int size;
    int MOD = 1e9+7;
    int dp[101][101][102];
    int helper(int i, int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(i == size) return minProfit == 0 ? 1 : 0;

        if(dp[i][n][minProfit] != -1) return dp[i][n][minProfit];

        int ans = helper(i+1, n, minProfit, group, profit);

        if(n >= group[i]){
            int new_profit = max(0, minProfit - profit[i]);
            ans = (ans + helper(i+1, n-group[i], new_profit, group, profit)) % MOD;
        }

        return dp[i][n][minProfit] = ans % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        size = group.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, n, minProfit, group, profit);
    }
};