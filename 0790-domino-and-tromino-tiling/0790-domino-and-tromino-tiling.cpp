class Solution {
public:
    int MOD = 1e9+7;
    int n;
    int dp[1001][4];
    int helper(int i, int state){
        if(i > n) return 0;
        if(i == n){
            if(state == 0 || state == 3) return 1;
            else return 0;
        }

        if(dp[i][state] != -1) return dp[i][state];

        long long ans = 0;

        if(state == 0){
            ans += (1LL * helper(i+1, 0) + helper(i+1, 1) + helper(i+1, 2) + helper(i+1, 3)) % MOD;
        }
        if(state == 1){
            ans += (1LL * helper(i+1, 2) + helper(i+1, 3)) % MOD;
        }
        if(state == 2){
            ans += (1LL * helper(i+1, 1) + helper(i+1, 3)) % MOD;
        }
        if(state == 3){
            ans += (1LL * helper(i+1, 0)) % MOD;
        }

        return dp[i][state] = ans % MOD;
    }

    int numTilings(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return helper(1, 0);
    }
};