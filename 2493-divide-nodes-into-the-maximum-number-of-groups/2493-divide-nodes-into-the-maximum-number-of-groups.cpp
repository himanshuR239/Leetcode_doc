class Solution {
public:
    bool isBip(int node, int c, vector<vector<int>> &adj, vector<int> &color, vector<int> &comp){
        color[node] = c;
        comp.push_back(node);

        for(int ngbr : adj[node]){
            if(color[ngbr] == 0){
                if(!isBip(ngbr, 3-c, adj, color, comp)) return false;
            }
            else if(color[ngbr] == color[node]) return false;
        }

        return true;
    }

    int maxDepth(int start, vector<vector<int>> &adj, int n){
        queue<int> q;
        vector<int> dist(n+1, -1);
        q.push(start);
        dist[start] = 1;
        int maxi = 1;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            maxi = max(maxi, dist[cur]);

            for(int ngbr : adj[cur]){
                if(dist[ngbr] == -1){
                    dist[ngbr] = dist[cur] + 1;
                    q.push(ngbr);
                }
            }
        }

        return maxi;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> color(n+1, 0); // to check bipartite and connected groups
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(color[i] == 0){
                vector<int> comp;
                if(!isBip(i, 1, adj, color, comp)) return -1; //odd length cycle

                int maxi = 0; // maxgroups for every component
                for(int node : comp){
                    maxi = max(maxi, maxDepth(node, adj, n)); //bfs to find maxgroup by starting from node
                }

                ans += maxi;
            }
        }

        return ans;
    }
};