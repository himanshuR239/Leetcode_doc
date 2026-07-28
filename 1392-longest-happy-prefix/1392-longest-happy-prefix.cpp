class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();

        vector<int> lps(n, 0);
        int l = 0;

        for(int i = 1; i < n; i++){
            while(l > 0 && s[i] != s[l]){
                l = lps[l-1];
            }
            if(s[i] == s[l]) l++;

            lps[i] = l;
        }

        return s.substr(0, lps[n-1]);
    }
};