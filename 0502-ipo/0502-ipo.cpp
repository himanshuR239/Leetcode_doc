class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> p;
        for(int i = 0 ; i < n; i++){
            p.push_back({capital[i], profits[i]});
        }
        sort(p.begin(), p.end());

        int ans = w;

        priority_queue<int> pq;
        int i = 0;

        while(k > 0){
            while(i < n && ans >= p[i].first){
                pq.push(p[i].second);
                i++;
            }

            if(pq.empty()) break;

            int prof = pq.top();
            pq.pop();

            ans += prof;
            k--;
        }

        return ans;
    }
};