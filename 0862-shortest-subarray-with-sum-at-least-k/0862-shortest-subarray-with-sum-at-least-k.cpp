class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 1e9;
        int j = 0;

        vector<long long> cumSum(n, 0);
        deque<int> dq;
    
        while(j < n){
            if(j == 0){
                cumSum[j] = nums[j];
            }
            else{
                cumSum[j] = cumSum[j-1] + nums[j];
            }

            if(cumSum[j] >= k) ans = min(ans, j+1);

            while(!dq.empty() && cumSum[j] - cumSum[dq.front()] >= k){
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cumSum[j] <= cumSum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }

        return ans == 1e9 ? -1 : ans;
    }
};