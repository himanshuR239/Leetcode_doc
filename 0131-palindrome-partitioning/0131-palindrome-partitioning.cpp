class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void solve(int ind, string &s, vector<string> &cur, vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(cur);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s, ind, i)){
                cur.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, cur, ans);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        vector<string> cur;
        solve(0, s, cur, ans);

        return ans;
    }
};