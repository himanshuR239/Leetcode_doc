class Solution {
public:
    int n;
    int MOD = 1e9+7;
    using ll = long long;
    // void solve(int ind, string &s, string cur, unordered_set<string> &st){
    //     if(ind == n){
    //         st.insert(cur);
    //         return;
    //     }

    //     solve(ind+1, s, cur, st);
    //     solve(ind+1, s, cur + s[ind], st);
    // }

    int distinctSubseqII(string s) {
        n = s.size();

        vector<int> sum(26, 0);
        for(int i = 0; i < n; i++){
            int tot = accumulate(sum.begin(), sum.end(), 1LL) % MOD;

            sum[s[i] - 'a'] = tot;
        }

        return accumulate(sum.begin(), sum.end(), 0LL) % MOD;
    }
};