class Solution {
public:
    int n;
    int dp[101];
    int solve(int ind, string &s){
        if(ind == n) return 1;

        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];

        int ways = solve(ind+1, s); //single digit

        if(ind+1 < n){ //double digit
            int two_dig = stoi(s.substr(ind, 2));
            if(two_dig >= 10 && two_dig <= 26){
                ways += solve(ind+2, s);
            }
        }

        return dp[ind] = ways;
    }

    int numDecodings(string s) {
        n = s.size();
        if(s[0] == '0') return 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};