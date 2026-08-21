class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;

        priority_queue<pair<int, int>> pq; // {dist, index}
        for(int i = 0; i < n; i++){
            int x = points[i][0];
            int y = points[i][1];

            int dis = (x*x + y*y);
            pq.push({dis, i});
        }

        while(pq.size() > k){
            pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};