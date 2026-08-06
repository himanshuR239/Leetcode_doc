class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(i >= k && nums[i - k] == 2){
                cnt--;
            }

            if(cnt % 2 == nums[i]){
                if(i+k > n) return -1;

                nums[i] = 2;
                cnt++;
                ans++;
            }
        }

        return ans;
    }
};