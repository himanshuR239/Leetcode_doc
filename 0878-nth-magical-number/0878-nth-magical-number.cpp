class Solution {
public:
    using ll = long long;
    int MOD = 1e9+7;

    bool check(ll mid, int n, int a, int b){
        ll hcf = gcd(a, b);
        ll lcm = (a * b) / hcf;

        ll tot = mid/a + mid/b - mid/lcm; //Inclusion-Exclusion Principle --> find the total number of multiples up to mid:
        // Adding mid/a and mid/b counts multiples of both twice, so subtracting mid/lcm removes the duplicates.

        return tot >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        ll low = 1, high = 1e15;
        ll ans = high;

        while(low <= high){
            ll mid = low + (high-low) / 2;

            if(check(mid, n, a, b)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans % MOD;
    }
};