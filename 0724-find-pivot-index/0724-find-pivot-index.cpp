class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int tot_sum = accumulate(nums.begin(), nums.end(), 0);

        int left_sum = 0;
        int right_sum = tot_sum;
        for(int i = 0; i < n; i++){
            right_sum -= nums[i];

            if(left_sum == right_sum) return i;

            left_sum += nums[i];
        }

        return -1;
    }
};