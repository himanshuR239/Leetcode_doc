class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if(n == 1) return 0;

        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') cnt1++;
            else cnt0++;
        }

        if(abs(cnt1 - cnt0) > 1) return -1;

        int even = 0;
        int odd = 0;
        for(int i = 0; i < n; i += 2){
            if(s[i] == '1') even++;
        }
        for(int i = 1; i < n; i += 2){
            if(s[i] == '1') odd++;
        }

        if(n % 2 == 0){
            return min(n/2 - even, n/2 - odd);
        }
        else{
            if(cnt1 > cnt0){
                return (n+1)/2 - even;
            }
            else{
                return (n)/2 - odd;
            }
        }

        return -1;
    }
};