class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        int tot = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            tot++;

            for(int ngbr : adj[cur]){
                indegree[ngbr]--;
                if(indegree[ngbr] == 0) q.push(ngbr);
            }
        }

        return tot == numCourses;
    }
};