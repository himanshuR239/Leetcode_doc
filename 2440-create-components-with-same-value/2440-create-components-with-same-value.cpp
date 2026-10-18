class Solution {
public:
    int dfs(int u, int parent, vector<vector<int>> &adj, vector<int> &nums, int tar){
        int sum = nums[u];

        for(int v : adj[u]){
            if(v == parent) continue;

            int childSum = dfs(v, u, adj, nums, tar);
            if(childSum == -1) return -1;

            sum += childSum;
        }

        return (sum == tar) ? 0 : sum;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int tot = accumulate(nums.begin(), nums.end(), 0);

        for(int k = n; k >= 1; k--){
            if(tot % k == 0){
                if(dfs(0, -1, adj, nums, tot/k) == 0){
                    return k-1;
                }
            }
        }

        return -1;
    }
};