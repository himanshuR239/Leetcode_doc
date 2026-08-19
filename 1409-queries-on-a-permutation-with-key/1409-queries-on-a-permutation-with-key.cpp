class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> p(m);
        for(int i = 0; i < m; i++){
            p[i] = i+1;
        }
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            int q = queries[i];

            int ind = -1;
            for(int j = 0; j < m; j++){
                if(p[j] == q){
                    ind = j;
                    break;
                }
            }
            ans[i] = ind;

            int num = p[ind];
            for(int j = ind; j >= 1; j--){
                p[j] = p[j-1];
            }
            p[0] = num;
        }

        return ans;
    }
};