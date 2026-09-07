class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); //{cost, node}

        vector<int> vis(n, 0);

        int ans = 0;
        int edges_connected = 0;

        while(!pq.empty() && edges_connected < n){
            auto [cost, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;
            ans += cost;
            edges_connected++;

            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);

                    pq.push({dist, i});
                }
            }
        }

        return ans;
    }
};