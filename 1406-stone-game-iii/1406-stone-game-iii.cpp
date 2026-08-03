class Solution {
public:
    int n;
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            int maxDiff = INT_MIN;
            int sum = 0;
            for(int k = 1; k <= 3 && i+k <= n; k++){
                sum += stoneValue[i+k-1];

                maxDiff = max(maxDiff, sum - dp[i+k]);
            }
            dp[i] = maxDiff;
        }

        if(dp[0] > 0) return "Alice";
        else if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};