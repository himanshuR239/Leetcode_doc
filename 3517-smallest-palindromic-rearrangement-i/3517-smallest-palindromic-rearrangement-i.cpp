class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid = n/2;

        string first_half = s.substr(0, mid);

        sort(first_half.begin(), first_half.end());
        
        string midd = "";
        if(n % 2 != 0){
            midd = s[mid];
        }

        string last = first_half;
        reverse(last.begin(), last.end());

        return first_half + midd + last;
    }
};