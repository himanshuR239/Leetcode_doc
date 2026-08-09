class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        long long ans = 0;
        long long cur = 0;
        for(int i = 0; i < n; i++){
            long long dif = target[i] - nums[i];

            if((dif > 0 && cur < 0) || (dif < 0 && cur > 0)){
                ans += abs(dif);
                cur = dif;
            }
            else{
                if(abs(dif) - abs(cur) > 0) ans += abs(dif) - abs(cur);
                cur = dif;
            }
        }

        return ans;
    }
};