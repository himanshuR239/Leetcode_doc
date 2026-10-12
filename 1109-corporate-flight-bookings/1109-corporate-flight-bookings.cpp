class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        int m = b.size();

        vector<int> ans(n, 0);

        for(int i = 0; i < m; i++){
            int x = b[i][0];
            int y = b[i][1];
            int val = b[i][2];

            ans[x-1] += val;
            if(y < n) ans[y] -= val;
        }

        for(int i = 1; i < n; i++){
            ans[i] += ans[i-1];
        }

        return ans;
    }
};