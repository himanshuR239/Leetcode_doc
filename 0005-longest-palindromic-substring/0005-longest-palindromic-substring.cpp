class Solution {
public:
    int isPalin(string &s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < n; i++){
            int len1 = isPalin(s, i, i);
            int len2 = isPalin(s, i, i+1);

            int len = max(len1, len2);

            if(len > maxLen){
                maxLen = len;
                start = i - (len-1)/2;
            }
        }

        return s.substr(start, maxLen);
    }
};