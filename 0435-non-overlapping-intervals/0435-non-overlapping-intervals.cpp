class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int prevLast = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] < prevLast){
                ans++;
                prevLast = min(prevLast, intervals[i][1]);
            }
            else prevLast = intervals[i][1];
        }
        return ans;
    }
};