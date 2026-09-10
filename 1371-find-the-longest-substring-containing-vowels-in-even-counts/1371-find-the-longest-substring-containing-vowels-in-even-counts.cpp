class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();

        unordered_map<int, int> first_seen;
        first_seen[0] = -1;

        int cur_mask = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                int char_bit = ch - 'a';          
                cur_mask ^= (1 << char_bit);
            }

            if(first_seen.count(cur_mask)){
                ans = max(ans, i - first_seen[cur_mask]);
            }
            else{
                first_seen[cur_mask] = i;
            }
        }

        return ans;
    }
};