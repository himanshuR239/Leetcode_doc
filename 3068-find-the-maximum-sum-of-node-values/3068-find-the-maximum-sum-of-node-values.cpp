class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        long long sum = 0;
        int flipCnt = 0;
        int minSacrifice = INT_MAX;

        for(int num : nums){
            long long flipVal = num ^ k;

            if(flipVal > num){
                sum += flipVal;
                flipCnt++;
            }
            else sum += num;

            int diff = abs(num - flipVal);
            minSacrifice = min(minSacrifice, diff);
        }
        
        if(flipCnt % 2 != 0){
            sum -= minSacrifice;
        }

        return sum;
    }
};