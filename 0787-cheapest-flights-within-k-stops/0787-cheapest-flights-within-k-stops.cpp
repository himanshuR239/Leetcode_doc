class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; //{k, cost, node}

        vector<int> dist(n , 1e9);
        dist[src] = 0;
        pq.push({0, 0, src});

        while(!pq.empty()){
            auto [stops, cost, node] = pq.top();
            pq.pop();

            if(stops > k) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;

                if(cost + edgeW < dist[adjNode]){
                    dist[adjNode] = cost + edgeW;
                    pq.push({stops+1, cost + edgeW, adjNode});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};