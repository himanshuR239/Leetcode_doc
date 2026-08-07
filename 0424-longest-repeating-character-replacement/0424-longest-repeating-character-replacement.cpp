class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> vec(26, 0);
        int l = 0, r = 0;

        int ans = 0;
        int max_freq = 0;
        while(r < n){
            vec[s[r] - 'A']++;
            max_freq = max(max_freq, vec[s[r] - 'A']);
            if(r-l+1 - max_freq > k){
                vec[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }

        return ans;
    }
};