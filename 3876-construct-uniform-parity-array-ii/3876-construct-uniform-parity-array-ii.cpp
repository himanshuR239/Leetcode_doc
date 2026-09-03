class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        int even  = 0;

        for(int num : nums){
            if(num % 2 == 0) even++;
            else odd++;
        }

        if(even == n || odd == n) return true;

        int smallest = *min_element(nums.begin(), nums.end());
        if(smallest % 2 == 1) return true;

        return false;
    }
};