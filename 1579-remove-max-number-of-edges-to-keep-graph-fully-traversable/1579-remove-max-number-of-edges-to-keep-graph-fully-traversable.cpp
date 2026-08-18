class DisjointSet{
    vector<int> rank, parent, size;
    int comp;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
        comp = n;
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return false;

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
        comp--;
        return true;
    }

    bool isSingleComp(){
        return comp == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);

        int edges_cnt = 0;

        for(auto it: edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];

            if(type == 3){
                bool add_alice = alice.unionByRank(u, v);
                bool add_bob = bob.unionByRank(u, v);

                if(add_alice || add_bob) edges_cnt++;
            }
        }
        for(auto it: edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];

            if(type == 1){
                if(alice.unionByRank(u, v)){
                    edges_cnt++;
                }
            }
            else if(type == 2){
                if(bob.unionByRank(u, v)){
                    edges_cnt++;
                }
            }
        }

        if(alice.isSingleComp() && bob.isSingleComp()) return edges.size() - edges_cnt;

        return -1;
    }
};