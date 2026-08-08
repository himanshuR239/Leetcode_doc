class Solution {
public:
    const int mod = 1e9+7;
    int numOfWays(int n) {
        long long aba = 6;
        long long abc = 6;
        for(int i=1 ;i<n ;i++){
            long long naba = (1LL*3*aba + 1LL*2*abc)%mod;
            long long nabc = (1LL*2*aba + 1LL*2*abc)%mod;
            aba = naba;
            abc = nabc;
        }
        return (aba+abc)%mod;
    }
};