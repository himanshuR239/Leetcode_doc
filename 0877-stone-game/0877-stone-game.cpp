class Solution {
public:
    int dp[501][501];

    // int solve(int l, int r, vector<int>& piles){
    //     if(l >= r) return 0;
    //     if(dp[l][r] != -1) return dp[l][r];

    //     //take left
    //     int left = piles[l] - solve(l+1, r, piles);

    //     // take right
    //     int right = piles[r] - solve(l, r-1, piles);

    //     return dp[l][r] = max(left, right);
    // }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++){
            dp[i][i] = piles[i];
        }

        for(int l = n-1; l >= 0; l--){
            for(int r = l+1; r < n; r++){
                //take left
                int left = piles[l] - dp[l+1][r];

                // take right
                int right = piles[r] - dp[l][r-1];

                dp[l][r] = max(left, right);
            }
        }

        if(dp[0][n-1] > 0) return true;
        return false;
    }
};