class Solution {
public:
    void solve(string &cur, vector<string> &ans, int open, int close, int n){
        if(cur.size() == 2*n){
            ans.push_back(cur);
            return;
        }

        if(open < n){
            cur.push_back('(');
            solve(cur, ans, open+1, close, n);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            solve(cur, ans, open, close+1, n);
            cur.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        string cur = "";
        solve(cur, ans, 0, 0, n);

        return ans;
    }
};