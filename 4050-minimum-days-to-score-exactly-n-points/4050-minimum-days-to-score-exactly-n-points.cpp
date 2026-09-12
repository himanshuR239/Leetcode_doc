class Solution {
public:
    int dp[100001];
    int solve(vector<pair<int, int>> &sum, int tar){
        if(tar == 0) return 0;

        if(dp[tar] != -1) return dp[tar];

        int ans = 1e9;
        for(auto &it : sum){
            int s = it.first;
            int cost = it.second;

            if(s > tar) break;

            ans = min(ans, cost + solve(sum, tar - s));
        }

        return dp[tar] = ans;
    }
    
    int minDays(int n) {

        vector<pair<int, int>> sum;
        for(int i = 1; ; i++){
            int s = i*(i+1)/2;
            if(s > n) break;
            sum.push_back({s, i+1});
        }

        memset(dp, -1, sizeof(dp));
        return solve(sum, n) - 1;
    }
};