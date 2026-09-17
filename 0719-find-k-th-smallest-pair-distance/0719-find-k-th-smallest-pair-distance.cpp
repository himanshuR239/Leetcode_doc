class Solution {
public:
    int n;
    bool check(int mid, int k, vector<int>& nums){
        int cnt = 0;

        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < n && nums[j] - nums[i] <= mid){
                j++;
            }
            cnt += j-i-1;
        }

        return cnt >= k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        n = nums.size();

        sort(nums.begin(), nums.end());

        int l = 0;
        int r = nums[n-1] - nums[0];

        int ans = r;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(check(mid, k, nums)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};