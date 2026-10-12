class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& b, int n) {
        int m = b.size();

        vector<int> ans(n, 0);

        for(int i = 0; i < m; i++){
            int l = b[i][0] - 1;
            int r = b[i][1] - 1;
            int val = b[i][2];

            for(int j = l; j <= r; j++){
                ans[j] += val;
            }
        }

        return ans;
    }
};