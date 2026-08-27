class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0];

        for(int i = 1; i < n; i++){
            pref[i] = nums[i] + pref[i-1];
        }

        int ans = INT_MIN;
        int min_pref = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, pref[i] - min_pref);
            min_pref = min(min_pref, pref[i]);
        }

        return ans;
    }
};