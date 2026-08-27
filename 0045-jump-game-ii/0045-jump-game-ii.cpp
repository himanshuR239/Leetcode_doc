class Solution {
public:
    int n;
    int jump(vector<int>& nums) {
        n = nums.size();
        int ans = 0;

        int cur = 0, farthest = 0;
        for(int i = 0; i < n-1; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == cur){
                ans++;
                cur = farthest;
            }
        }

        return ans;
    }
};