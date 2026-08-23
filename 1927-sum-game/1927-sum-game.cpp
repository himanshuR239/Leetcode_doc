class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumL = 0;
        int sumR = 0;
        int l = 0, r = 0;

        for(int i = 0; i < n/2; i++){
            if(num[i] == '?') l++;
            else sumL += (num[i] - '0');
        }
        for(int i = n/2; i < n; i++){
            if(num[i] == '?') r++;
            else sumR += (num[i] - '0');
        }

        return (sumL - sumR)*2 != (r-l)*9;
    }
};