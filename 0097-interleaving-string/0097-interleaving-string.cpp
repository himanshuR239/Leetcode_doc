class Solution {
public:
    int n1, n2;
    int dp[101][101];
    bool solve(int ind1, int ind2, string &s1, string &s2, string &s3){
        if(ind1 == n1 && ind2 == n2) return true;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int ind3 = ind1 + ind2;
        bool ans = false;
        if(ind1 < n1 && s1[ind1] == s3[ind3]){
            ans = ans || solve(ind1+1, ind2, s1, s2, s3);
        }
        if(ind2 < n2 && s2[ind2] == s3[ind3]){
            ans = ans || solve(ind1, ind2+1, s1, s2, s3);
        }

        return dp[ind1][ind2] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size();
        n2 = s2.size();
        
        if(n1 + n2 != s3.size()) return false;

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2, s3);
    }
};