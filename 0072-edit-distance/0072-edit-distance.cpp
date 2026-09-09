class Solution {
public:
    int n1, n2;
    int dp[501][501];
    int solve(int i, int j, string &word1, string &word2){
        if(i >= n1) return n2-j;
        if(j >= n2) return n1-i;
        
        if(dp[i][j] != -1) return dp[i][j];
 
        int ans = 1e9;
        if(word1[i] == word2[j]) ans = solve(i+1, j+1, word1, word2);
        else{
            ans = min(ans, 1 + solve(i, j+1, word1, word2)); //insert
            ans = min(ans, 1 + solve(i+1, j, word1, word2)); //delete
            ans = min(ans, 1 + solve(i+1, j+1, word1, word2)); //replace
        } 

        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        n1 = word1.size();
        n2 = word2.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, word1, word2);
    }
};