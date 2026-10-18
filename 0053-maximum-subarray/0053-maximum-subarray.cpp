class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int sum = 0;

        int start = 0;
        int ansS = -1;
        int ansE = -1;

        for(int i = 0; i < n; i++){
            if(sum == 0){
                start = i;
            }

            sum += nums[i];

            if(sum > maxi){
                maxi = sum;
                ansS = start;
                ansE = i;
            }

            if(sum < 0){
                sum = 0;
            }
        }

        return maxi;
    }
};