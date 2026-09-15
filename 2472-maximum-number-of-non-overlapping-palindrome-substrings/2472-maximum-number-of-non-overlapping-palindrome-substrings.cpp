class Solution {
public:
    bool isPalindrome(int l, int r, string &s){
        while(l < r){
            if(s[l] != s[r]) return false;

            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1, 0);

        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1]; // case 1

            // case 2
            if(i >= k && isPalindrome(i-k, i-1, s)){
                dp[i] = max(dp[i], 1 + dp[i-k]);
            }

            // case 3
            if(i >= k+1 && isPalindrome(i-k-1, i-1, s)){
                dp[i] = max(dp[i], 1 + dp[i-k-1]);
            }
        }

        return dp[n];
    }
};