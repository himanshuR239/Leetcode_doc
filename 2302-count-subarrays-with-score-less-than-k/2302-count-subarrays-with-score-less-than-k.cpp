class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        ll ans = 0;
        int l = 0;

        ll sum = 0;
        for(int r = 0; r < n; r++){
            sum += nums[r];

            while(l <= r && sum*(r-l+1) >= k){
                sum -= nums[l];
                l++;
            }

            ans += (r-l+1);
        }

        return ans;
    }
};