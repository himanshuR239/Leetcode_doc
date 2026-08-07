class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        vector<int> vec(256, -1);
        int ans = 0;
        int l = 0, r = 0;

        while(r < n){
            if(vec[s[r]] != -1){
                if(vec[s[r]] >= l){
                    l = vec[s[r]] + 1;
                }
            }

            ans = max(ans, r-l+1);
            vec[s[r]] = r;
            r++;
        }

        return ans;
    }
};