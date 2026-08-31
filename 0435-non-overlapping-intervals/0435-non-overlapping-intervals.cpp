class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int cnt = 0;
        int prev = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(prev <= intervals[i][0]){
                cnt++;
                prev = intervals[i][1];
            }
        }

        return n - cnt -1;
    }
};