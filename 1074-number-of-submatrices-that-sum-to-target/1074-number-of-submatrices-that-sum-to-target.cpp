class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for(int r1 = 0; r1 < m; r1++){
            vector<int> col_sum(n, 0);
            for(int r2 = r1; r2 < m; r2++){
                for(int c = 0; c < n; c++){
                    col_sum[c] += matrix[r2][c];
                }
                map<int, int> mpp;
                mpp[0] = 1;
                int presum = 0;
                for(int i = 0; i < n; i++){
                    presum += col_sum[i];
                    int rem = presum - target;
                    ans += mpp[rem];
                    mpp[presum]++;
                }
            }
        }
        return ans;
    }
};