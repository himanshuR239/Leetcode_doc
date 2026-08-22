class Solution {
public:
    void solve(int ind, vector<int> & cur, vector<vector<int>> &ans, vector<int>& nums){
        ans.push_back(cur);

        for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;

            cur.push_back(nums[i]);
            solve(i+1, cur, ans, nums);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        solve(0, cur, ans, nums);

        return ans;
    }
};