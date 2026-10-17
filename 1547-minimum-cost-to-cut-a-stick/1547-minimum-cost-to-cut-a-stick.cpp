class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, int n, vector<int>& cuts){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int ind = i; ind <= j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, n, cuts) + solve(ind+1, j, n, cuts);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        sort(cuts.begin(), cuts.end());

        memset(dp, -1, sizeof(dp));

        return solve(1, c, n, cuts);
    }
};