class Solution {
public:
    int n;
    int dp[101][101];

    int findcost(vector<int>& houses, int i, int j){
        int cost = 0;
        int med = houses[(i + j) / 2];

        for(int ind = i; ind <= j; ind++){
            cost += abs(houses[ind] - med);
        }

        return cost;
    }

    int helper(int i, int k, vector<int>& houses){
        if(k == 1) return findcost(houses, i, n-1);
        if(i >= n) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            int curCost = findcost(houses, i, j);
            int rem = helper(j+1, k-1, houses);

            mini = min(mini, curCost + rem); 
        }

        return dp[i][k] = mini;
    }

    int minDistance(vector<int>& houses, int k) {
        n = houses.size();
        sort(houses.begin(), houses.end());

        memset(dp, -1, sizeof(dp));
        return helper(0, k, houses);
    }
};