class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> quer;
        for(int i = 0; i < m; i++){
            quer.push_back({queries[i], i});
        }
        sort(quer.begin(), quer.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{size, right}
        vector<int> ans(m, -1);

        int i = 0;
        for(auto &[q, idx] : quer){
            int mini = 1e9;
            while(i < n && q >= intervals[i][0]){
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r-l+1, r});
                i++;
            }

            while(!pq.empty() && pq.top().second < q) pq.pop();
            
            if(!pq.empty()) ans[idx] = pq.top().first;
        }

        return ans;
    }
};