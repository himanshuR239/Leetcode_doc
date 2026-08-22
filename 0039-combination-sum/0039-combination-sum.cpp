class Solution {
public:
    void solve(int ind, vector<int> &cur, int sum, vector<vector<int>> &ans, vector<int>& candidates, int target){
        if(sum == target){
            ans.push_back(cur);
            return;
        }
        if(sum > target) return;

        for(int i = ind; i < candidates.size(); i++){
            cur.push_back(candidates[i]);
            sum += candidates[i];

            solve(i, cur, sum, ans, candidates, target);

            cur.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> cur;
        solve(0, cur, 0, ans, candidates, target);

        return ans;
    }
};