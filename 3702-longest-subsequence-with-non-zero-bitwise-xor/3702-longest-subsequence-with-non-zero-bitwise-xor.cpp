class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int tot_xor = 0;
        bool non_zero = false;
        for(int i = 0; i < n; i++){
            tot_xor ^= nums[i];

            if(nums[i] > 0) non_zero = true;
        }

        if(!non_zero) return 0;
        if(tot_xor != 0) return n;
        return n-1;
    }
};