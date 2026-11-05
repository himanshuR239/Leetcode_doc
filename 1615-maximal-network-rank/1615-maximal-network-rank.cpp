class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        vector<vector<bool>> isconnected(n, vector<bool>(n, false));

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;

            isconnected[u][v] = true;
            isconnected[v][u] = true;
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int cur_rank = degree[i] + degree[j];

                if(isconnected[i][j]){
                    cur_rank--;
                }

                ans = max(ans, cur_rank);
            }
        }

        return ans;
    }
};