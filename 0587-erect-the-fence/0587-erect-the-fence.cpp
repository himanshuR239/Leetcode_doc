class Solution {
public:
    long long crossProd(vector<int> &p, vector<int> &q, vector<int> &r){
        return 1LL*(q[0]-p[0])*(r[1]-q[1]) - 1LL*(q[1]-p[1])*(r[0]-q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n <= 3) return trees;

        sort(trees.begin(), trees.end());

        vector<vector<int>> hull;

        for(int i = 0; i < n; i++){
            while(hull.size() >= 2 && crossProd(hull[hull.size() - 2], hull.back(), trees[i]) < 0){
                hull.pop_back();
            }

            hull.push_back(trees[i]);
        }

        for(int i = n-2; i >= 0; i--){
            while(hull.size() >= 2 && crossProd(hull[hull.size() - 2], hull.back(), trees[i]) < 0){
                hull.pop_back();
            }

            hull.push_back(trees[i]);
        }

        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};