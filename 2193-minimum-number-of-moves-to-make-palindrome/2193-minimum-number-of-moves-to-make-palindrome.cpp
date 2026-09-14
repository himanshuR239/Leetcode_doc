class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();

        int l = 0;
        int r = n-1;

        int ans = 0;
        while(l < r){
            int k = r;
            while(k > l && s[k] != s[l]){
                k--;
            }

            if(k == l){
                swap(s[l], s[l+1]);
                ans++;
            }
            else{
                while(k < r){
                    swap(s[k], s[k+1]);
                    ans++;
                    k++;
                }
                l++;
                r--;
            }
        }

        return ans;
    }
};