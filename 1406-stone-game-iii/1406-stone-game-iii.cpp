class Solution {
public:
    int n;
    int helper(int i, vector<int>& stoneValue, vector<int> &dp){
        if(i >= n) return 0;

        if(dp[i] != INT_MIN) return dp[i];
        int maxDiff = INT_MIN;
        int sum = 0;

        for(int k = 1; k <= 3 && i+k <= n; k++){
            sum += stoneValue[i+k-1];

            maxDiff = max(maxDiff, sum - helper(i+k, stoneValue, dp));
        }

        return dp[i] = maxDiff;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        vector<int> dp(n, INT_MIN);
        int scoreDiff = helper(0, stoneValue, dp);

        if(scoreDiff > 0) return "Alice";
        else if(scoreDiff < 0) return "Bob";
        return "Tie";
    }
};