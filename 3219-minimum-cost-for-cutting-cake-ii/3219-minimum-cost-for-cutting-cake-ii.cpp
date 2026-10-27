class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int h = 0, v = 0;
        int h_pieces = 1, v_pieces = 1;
        long long total_cost = 0;

        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] >= verticalCut[v]) {
                total_cost += horizontalCut[h] * v_pieces;
                h_pieces++;
                h++;
            } else {
                total_cost += verticalCut[v] * h_pieces;
                v_pieces++;
                v++;
            }
        }

        // Process remaining horizontal cuts
        while (h < horizontalCut.size()) {
            total_cost += horizontalCut[h] * v_pieces;
            h++;
        }

        // Process remaining vertical cuts
        while (v < verticalCut.size()) {
            total_cost += verticalCut[v] * h_pieces;
            v++;
        }

        return total_cost;
    }
};