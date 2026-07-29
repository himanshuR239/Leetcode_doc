class Solution {
public:
    string shortestPalindrome(string s) {

        int size = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        int n = temp.size();
        vector<int> lps(n, 0);
        int len = 0;

        for(int i = 1; i < n; i++){
            while(len > 0 && temp[i] != temp[len]){
                len = lps[len-1];
            }

            if(temp[i] == temp[len]) len++;
            
            lps[i] = len;
        }

        string pal = temp.substr(lps[n-1], size-lps[n-1]);
        string pre = pal;
        reverse(pre.begin(), pre.end());

        return pre + s;

    }
};