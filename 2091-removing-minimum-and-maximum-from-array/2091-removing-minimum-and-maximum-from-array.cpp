class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int x = -1;
        int y = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                x = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                y = i;
            }
        }
        if(x > y) swap(x, y);
        return min({x+1+n-y, max(n-x, n-y), max(x+1, y+1)});
    }
};