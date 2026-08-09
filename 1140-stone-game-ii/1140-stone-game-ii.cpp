class Solution {
public:
    int n;
    int dp[101][101];

    int solve(int ind, int M, vector<int>& piles, vector<int> &suf_sum){
        if(n-ind <= 2*M) return suf_sum[ind];

        if(dp[ind][M] != -1) return dp[ind][M];

        int maxi = 0;
        for(int x = 1; x <= 2*M; x++){
            int next_score = solve(ind+x, max(M, x), piles, suf_sum);
            int cur_score =  suf_sum[ind] - next_score;

            maxi = max(maxi, cur_score);
        }

        return dp[ind][M] = maxi;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        vector<int> suf_sum(n, 0);
        suf_sum[n-1] = piles[n-1];

        for(int i = n-2; i >= 0; i--){
            suf_sum[i] = suf_sum[i+1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));
        // {i, M}
        return solve(0, 1, piles, suf_sum);
    }
};