class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;

        for(int i = 0; i <= n; i++){
            intervals.push_back({i-ranges[i], i+ranges[i]});
        }
        sort(intervals.begin(), intervals.end());

        int ans = 0;
        int cur = 0;
        int max_reach = 0;
        int i = 0;

        while(cur < n){
            while(i <= n && intervals[i][0] <= cur){
                max_reach = max(max_reach, intervals[i][1]);
                i++;
            }

            if(max_reach <= cur) return -1;

            ans++;
            cur = max_reach;
        }

        return ans;
    }
};