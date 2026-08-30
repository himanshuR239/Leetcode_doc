class Solution {
public:
    int m;
    int dp[301];
    bool solve(int ind, string s, unordered_set<string> &st){
        if(ind >= m) return true;
        if(dp[ind] != -1) return dp[ind];
        string t = "";
        bool ans = false;
        for(int i = ind; i < m; i++){
            t += s[i];

            if(st.count(t) && solve(i+1, s, st)){
                ans = true;
            }
        }

        return dp[ind] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        m = s.size();
        int n = wordDict.size();

        unordered_set<string> st;
        for(int i = 0; i < n; i++){
            st.insert(wordDict[i]);
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, s, st);
    }
};