class Solution {
public:
    void solve(int ind, vector<int> &cur, int sum, vector<vector<int>> &ans, vector<int>& candidates, int target){
        if(sum == target){
            ans.push_back(cur);
            return;
        }

        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(sum + candidates[i] > target) break;

            cur.push_back(candidates[i]);
            solve(i+1, cur, sum + candidates[i], ans, candidates, target);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        solve(0, cur, 0, ans, candidates, target);

        return ans;
    }
};