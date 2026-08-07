class Solution {
public:
    // void solve(int r, int cur_sum, vector<vector<int>>& mat, vector<int> &sum){
    //     if(r == mat.size()){
    //         sum.push_back(cur_sum);
    //         return;
    //     }

    //     for(int c = 0; c < mat[r].size(); c++){
    //         solve(r+1, cur_sum + mat[r][c], mat, sum);
    //     }
    // }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> prev_sum = mat[0];

        if(prev_sum.size() > k) prev_sum.resize(k);

        for(int i = 1; i < m; i++){
            vector<int> cur_sum;

            for(int prev : prev_sum){
                for(int num : mat[i]){
                    cur_sum.push_back(prev + num);
                }
            }

            sort(cur_sum.begin(), cur_sum.end());

            if(cur_sum.size() > k) cur_sum.resize(k);

            prev_sum = cur_sum;
        }
        
        return prev_sum[k-1];
    }
};