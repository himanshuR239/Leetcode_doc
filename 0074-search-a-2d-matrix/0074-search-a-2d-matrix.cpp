class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = m*n;
        while(i <= j){
            int mid = (i + j) / 2;
            if(mid/n >= 0 && mid/ n < m && mid%n >= 0 && mid%n < n && matrix[mid/n][mid%n] == target) return true;
            else if(mid/n >= 0 && mid/ n < m && mid%n >= 0 && mid%n < n && matrix[mid/n][mid%n] > target) j = mid-1;
            else i = mid+1;
        }

        return false;
    }
};