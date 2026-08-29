class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DisjointSet ds(n);

        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++){
            pairs.push_back({nums[i], i});
        }

        sort(pairs.begin(), pairs.end());

        for(int i = 1; i < n; i++){
            int dif = pairs[i].first - pairs[i-1].first;

            if(dif <= limit){
                ds.unionBySize(pairs[i].second, pairs[i-1].second);
            }
        }

        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            int x = ds.findUPar(i);
            mpp[x].push_back(i);
        }

        for(auto it : mpp){
            auto &vec = it.second;
            vector<int> temp;

            for(int i = 0; i < vec.size(); i++){
                temp.push_back(nums[vec[i]]);
            }
            sort(temp.begin(), temp.end());

            for(int i = 0; i < vec.size(); i++){
                int idx = vec[i];
                nums[idx] = temp[i];
            }
        }

        return nums;
    }
};