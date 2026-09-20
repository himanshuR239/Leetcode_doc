class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> p;
        for(int i = 0; i < n; i++){
            double r = (double)wage[i] / quality[i];
            p.push_back({r, quality[i]});
        }

        sort(p.begin(), p.end());

        priority_queue<int> pq;
        int tot = 0;

        double ans = 1e18;
        for(auto [r, q] : p){
            pq.push(q);
            tot += q;

            if(pq.size() > k){
                tot -= pq.top();
                pq.pop();
            }

            if(pq.size() == k){
                ans = min(ans, r * tot);
            }
        }

        return ans;
    }
};