class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int ind = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == k){
                ind = i;
                break;
            }
        }

        unordered_map<int, int> mpp;
        int cnt = 0;

        for(int i = ind; i >= 0; i--){
            if(nums[i] > k) cnt++;
            else if(nums[i] < k) cnt--;

            mpp[cnt]++;
        }

        cnt = 0;
        int ans = 0;
        for(int i = ind; i < n; i++){
            if(nums[i] > k) cnt++;
            else if(nums[i] < k) cnt--;

            ans += mpp[-cnt];
            ans += mpp[1-cnt];
        }

        return ans;
    }
};