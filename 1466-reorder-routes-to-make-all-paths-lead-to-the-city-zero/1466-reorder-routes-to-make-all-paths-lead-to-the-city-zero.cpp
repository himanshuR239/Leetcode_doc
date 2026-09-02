class Solution {
public:
    int ans;
    void dfs(int node, int parent, vector<vector<int>> &adj, set<pair<int, int>> &st){
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(st.contains({node, it})){
                ans++;
            }
            dfs(it, node, adj, st);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        set<pair<int, int>> st;
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            st.insert({it[0], it[1]});
        }

        ans = 0;
        dfs(0, -1, adj, st);
        return ans;
    }
};