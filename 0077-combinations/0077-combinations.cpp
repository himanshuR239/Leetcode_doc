class Solution {
public:
    void solve(int ind, int n, int k, vector<int> cur, vector<vector<int>> &ans){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }

        for(int i = ind; i <= n; i++){
            cur.push_back(i);
            solve(i+1, n, k, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> cur;
        solve(1, n, k, cur, ans);

        return ans;
    }
};