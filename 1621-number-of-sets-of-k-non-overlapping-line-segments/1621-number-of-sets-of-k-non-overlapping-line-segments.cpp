class Solution {
public:
    int dp[1000][1000][3];
    using ll = long long;
    int MOD = 1e9+7;
    int solve(int i, int n, int k, int is_started){
        if(k == 0) return 1;
        if(i >= n) return 0;

        if(dp[i][k][is_started] != -1) return dp[i][k][is_started];

        ll ans = 0;
        if(is_started == 0){
            ans = (solve(i+1, n, k, 0)) % MOD; //skip

            ans = (ans + solve(i+1, n, k, 1)) % MOD; //start line
        }
        else{
            ans = solve(i+1, n, k, 1) % MOD; // continue line

            ans = (ans + solve(i, n, k-1, 0)) % MOD; // end line
        }

        return dp[i][k][is_started] = ans % MOD;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, k, 0);
    }
};