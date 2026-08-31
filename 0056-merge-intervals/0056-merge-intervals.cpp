class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int i = 0;
        for(auto &interval : intervals){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
                i++;
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                i++;
            }
        }

        return ans;
    }
};