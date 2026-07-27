class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9+7;
        vector<long long> vec(26, 0);
        
        for(int i = 0; i < n; i++){
            long long sum = accumulate(vec.begin(), vec.end(), 1LL) % MOD;

            vec[s[i] - 'a'] = sum;
        }

        return accumulate(vec.begin(), vec.end(), 0LL) % MOD;
    }
};