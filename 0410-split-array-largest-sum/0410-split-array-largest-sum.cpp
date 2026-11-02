class Solution {
private:
    int split(vector<int>& nums, int k, int maxSum){
        int num = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > maxSum){
                num++;
                sum = nums[i];
            }
            else sum += nums[i];
        }
        return num;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;
            int maxi = split(nums, k, mid);

            if(maxi <= k){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};