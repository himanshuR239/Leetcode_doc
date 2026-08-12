class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int ans = 0;
        unordered_map<int, int> mpp;
        for(int j = 0; j < n; j++){
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
        }

        return ans;
    }
};