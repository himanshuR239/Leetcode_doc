class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        pq.push({grid[0][0], {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.first;
            int r = it.second.first;
            int c = it.second.second;

            ans = max(ans, node);
            if(r == n-1 && c == n-1) return ans;

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == 1e9){
                    dist[nr][nc] = 0;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }

        return -1;
    }
};