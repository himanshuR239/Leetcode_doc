class Solution {
public:
    int N;
    int MOD = 1e9+7;
    int dp[20001][5];

    int charToIdx(char c){
        if(c == 'a') return 0;
        else if(c == 'e') return 1;
        else if(c == 'i') return 2;
        else if(c == 'o') return 3;
        else return 4;
    }

    int solve(int i, char prev){
        if(i==N) return 1;

        int prevIdx = charToIdx(prev);
        if(dp[i][prevIdx] != -1) return dp[i][prevIdx];
        long long ans = 0;

        if(prev == 'a') ans = (ans + solve(i+1, 'e')) % MOD;
        else if(prev == 'e'){
            ans = (ans + solve(i+1, 'a') + solve(i+1, 'i')) % MOD;
        }
        else if(prev == 'i'){
            ans = (ans + solve(i+1, 'a') + solve(i+1, 'e') + solve(i+1, 'o') + solve(i+1, 'u')) % MOD;
        }
        else if(prev == 'o'){
            ans = (ans + solve(i+1, 'i') + solve(i+1, 'u')) % MOD;
        }
        else{
            ans = (ans + solve(i+1, 'a')) % MOD;
        }
        return dp[i][prevIdx] = ans;
    }

    int countVowelPermutation(int n) {
        N = n;
        string s = {'a', 'e', 'i', 'o', 'u'};

        memset(dp, -1, sizeof(dp));

        long long ans = 0;
        for(int i = 0; i < s.size(); i++){
            ans = (ans + solve(1, s[i])) % MOD;
        }

        return ans;
    }
};