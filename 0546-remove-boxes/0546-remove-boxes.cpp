class Solution {
public:
    int dp[100][100][100];
    int solve(int l, int r, int k, vector<int>& boxes){
        if(l > r) return 0;

        while(r > l && boxes[r] == boxes[r-1]){
            r--;
            k++;
        }
        if(dp[l][r][k] != -1) return dp[l][r][k];

        int ans = (k+1)*(k+1) + solve(l, r-1, 0, boxes);

        for(int m = l; m < r; m++){
            if(boxes[m] == boxes[r]){
                ans = max(ans, solve(m+1, r-1, 0, boxes) + solve(l, m, k+1, boxes));
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        // TWO OPTIONS EITHER REMOVE K OR 1
        memset(dp, -1, sizeof(dp));
        // i, j, k
        return solve(0, n-1, 0, boxes);
    }
};