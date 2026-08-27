class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int cur_sum = 0;

        for(int i = 0; i < n; i++){
            cur_sum = max(nums[i], cur_sum + nums[i]);

            ans = max(ans, cur_sum);
        }

        return ans;
    }
};