class Solution {
public:
    using ll = long long;
    int dfs(int u, int par, int curDist, int signalSpeed, vector<vector<pair<int, int>>> &adj){
        ll cnt = (curDist % signalSpeed == 0) ? 1 : 0;

        for(auto [v, wt]: adj[u]){
            if(v != par){
                cnt += dfs(v, u, curDist + wt, signalSpeed, adj);
            }
        }

        return cnt;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            int curSum = 0;

            for(auto [ngbr, wt]: adj[i]){
                int validNodes = dfs(ngbr, i, wt, signalSpeed, adj);
                ans[i] += curSum * validNodes;
                curSum += validNodes;
            }
        }
        return ans;
    }
};