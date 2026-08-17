class Solution {
public:
    #define p pair<int, pair<int, int>>
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> ans(m, vector<int>(n, 1e9));
        ans[0][0] = 0;

        int drow[] = {0, 0, 0, 1, -1};
        int dcol[] = {0, 1, -1, 0, 0};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 1; i <= 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int new_cost = cost + ((grid[r][c] == i) ? 0 : 1);

                    if(new_cost < ans[nr][nc]){
                        ans[nr][nc] = new_cost;
                        pq.push({new_cost, {nr, nc}});
                    }
                }
            }
        }

        return ans[m-1][n-1];
    }
};