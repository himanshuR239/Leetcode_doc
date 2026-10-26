class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int cur, int prev,  vector<pair<int, int>> &pairs){
        if(cur == n) return 0;

        if(dp[cur][prev+1] != -1) return dp[cur][prev+1];

        int notTake = solve(cur+1, prev, pairs);

        int take = 0;
        if(prev == -1 || pairs[cur].second >= pairs[prev].second)
            take = pairs[cur].second + solve(cur+1, cur, pairs);

        return dp[cur][prev+1] = max(take, notTake);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();

        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++){
            pairs.push_back({ages[i], scores[i]});
        }

        sort(pairs.begin(), pairs.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, pairs);
    }
};