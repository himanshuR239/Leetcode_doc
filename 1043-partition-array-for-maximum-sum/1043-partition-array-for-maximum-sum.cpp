class Solution {
public:
    int n;
    int dp[501];
    int solve(int ind, vector<int>& arr, int k){
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int maxi = INT_MIN;
        int max_el = 0;

        for(int p = 1; p <= k && ind+p <= n; p++){
            max_el = max(max_el, arr[ind+p-1]);

            int sum = max_el*p + solve(ind+p, arr, k);
            maxi = max(maxi, sum);
        }

        return dp[ind] = maxi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, arr, k);
    }
};