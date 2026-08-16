class Solution {
public:
    int n;
    int dp[301][27];

    int dis(int a, int b){
        if(a == 26) return 0;
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }
    int solve(int k, int other, string &word){
        if(k == n) return 0;

        if(dp[k][other] != -1) return dp[k][other];

        int cur = word[k] - 'A';
        int prev = word[k-1] - 'A';

        int op1 = dis(prev, cur) + solve(k+1, other, word);
        int op2 = dis(other, cur) + solve(k+1, prev, word);

        return dp[k][other] = min(op1, op2);
    }

    int minimumDistance(string word) {
        n = word.size();
        memset(dp, -1, sizeof(dp));

        return solve(1, 26, word);
    }
};