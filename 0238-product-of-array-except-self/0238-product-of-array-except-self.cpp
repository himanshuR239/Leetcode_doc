class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        long long prod = 1;
        int zero = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zero++;
            else prod *= nums[i];
        } 

        for(int i = 0; i < n; i++){
            if(zero > 1) ans[i] = 0;
            else if(zero == 1){
                if(nums[i] == 0) ans[i] = prod;
                else ans[i] = 0;
            }
            else ans[i] = prod / nums[i];
        }

        return ans;
    }
};