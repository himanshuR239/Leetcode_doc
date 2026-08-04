class Solution {
public:
    vector<vector<double>> dp;
    vector<vector<int>> adj;
    int n, t, target;

    void solve(int node, double prob, int parent, int time){
        if(time  > t) return;
        dp[node][time] = prob;

        int cnt = 0;
        for(auto it : adj[node]){
            if(it != parent) cnt++;
        }

        if(cnt == 0){
            for(int i = time; i <= t; i++){
                dp[node][i] = prob;
            }
        }
        else{
            if(time == t) return;

            for(auto it : adj[node]){
                if(it != parent){
                    solve(it, prob / cnt, node, time + 1);
                }
            }
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        this->n = n;
        this->t = t;
        this->target = target;

        dp.resize(n+1, vector<double>(t+1, 0));
        adj.resize(n+1);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n+1, 0);

        solve(1, 1.0, -1, 0);

        return dp[target][t];
    }
};