class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1) return 0;

        int tarMask = (1 << n) - 1; //111... all nodes are visited

        queue<pair<int, int>> q; //{curNode, mask}
        
        vector<vector<bool>> vis(n, vector<bool>(1<<n, false)); //vis[node][mask]


        // multisource bfs
        for(int i = 0; i < n; i++){
            int imask = 1 << i;
            q.push({i, imask});
            vis[i][imask] = true;
        }

        int cnt = 0;

        while(!q.empty()){
            int sz = q.size(); //level-wise traverse
            while(sz > 0){
                auto [curNode, curMask] = q.front();
                q.pop();

                for(int ngbr : graph[curNode]){
                    int nMask = curMask | (1 << ngbr); //sets the neighbor-th bit to 1 in curMask

                    if(nMask == tarMask){
                        return cnt + 1;
                    }

                    if(!vis[ngbr][nMask]){
                        vis[ngbr][nMask] = true;
                        q.push({ngbr, nMask});
                    }
                }
                sz--;
            }
            cnt++;
        }

        return -1;
    }
};