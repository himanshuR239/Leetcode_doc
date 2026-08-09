class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        vector<int> ans(n, 0);
        ans[0] = target[0];
        for(int i = 1; i < n; i++){
            if(target[i] <= target[i-1]){
                ans[i] = ans[i-1];
            }
            else{
                ans[i] = ans[i-1] + (target[i] - target[i-1]);
            }
        }

        return ans[n-1];
    }
};