class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int len = n;

        long long tot_sum = 0;
        for(int num : nums) tot_sum += num;

        if(tot_sum % p == 0) return 0;

        int tar = tot_sum % p;

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int cur_sum = 0;
        for(int i = 0; i < n; i++){
            cur_sum = (cur_sum + nums[i]) % p; 

            int need = (cur_sum - tar + p) % p;

            if(mpp.find(need) != mpp.end()){
                len = min(len, i - mpp[need]);
            }

            mpp[cur_sum] = i;
        }

        return (len == n) ? -1 : len;

    }
};