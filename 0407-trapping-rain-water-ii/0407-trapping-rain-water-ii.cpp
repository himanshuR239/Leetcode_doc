class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if(n == 0) return 0;
        int m = heightMap[0].size();
        if(m == 0) return 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // {height, {r, c}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;
        int maxHeight = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!pq.empty()){
            auto[h, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            maxHeight = max(maxHeight, h);

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    if(heightMap[nrow][ncol] < maxHeight){
                        ans += maxHeight - heightMap[nrow][ncol];
                    }

                    pq.push({heightMap[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return ans;
    }
};