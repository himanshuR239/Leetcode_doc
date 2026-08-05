class Solution {
public:
    bool dfs2(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &vis2){
        // if(vis[node] == 1) return false;

        vis2[node] = 1;
        // ans.push_back(node);

        for(auto it : adj[node]){
            if(vis[it]) return false;
            if(!vis2[it]){
                if(!dfs2(it, adj, vis, vis2)) return false;
            }
        }

        return true;
    }

    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        // if(vis[node]) return;
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto it : invocations){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(n, 0), vis2(n, 0);
        dfs(k, adj, vis);

        bool flag = true;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!vis[i] && !vis2[i]){
                flag = dfs2(i, adj, vis, vis2);
                if(!flag){
                    for(int j = 0; j < n; j++){
                        ans.push_back(j);
                    }
                    return ans;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};