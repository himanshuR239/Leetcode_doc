class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<int> diff(1001, 0);
        for(int i = 0; i < n; i++){
            int pass = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            diff[from] += pass;
            diff[to] -= pass;
        }

        int cur = 0;
        for(int i = 0; i <= 1000; i++){
            cur += diff[i];
            if(cur > capacity) return false;
        }

        return true;
    }
};