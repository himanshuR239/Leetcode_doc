class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);

        vector<vector<int>> adj(n);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for(int ngbr : adj[cur]){
                indegree[ngbr]--;

                if(indegree[ngbr] == 0){
                    q.push(ngbr);
                }
            }
        }

        return ans.size() == n ? ans : vector<int>();
    }
};