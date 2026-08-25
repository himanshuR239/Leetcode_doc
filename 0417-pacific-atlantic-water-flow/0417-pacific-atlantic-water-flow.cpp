class Solution {
public:
    int m;
    int n;

    bool isValid(int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n) return false;
        return true;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> q;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int r = 0; r < m; r++){
            q.push({r, 0});
            pacific[r][0] = true;

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second; 
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if(isValid(nrow, ncol) && heights[nrow][ncol] >= heights[row][col] && !pacific[nrow][ncol]){
                        pacific[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        while(!q.empty()) q.pop();
        for(int c = 0; c < n; c++){
            q.push({0, c});
            pacific[0][c] = true;

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second; 
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if(isValid(nrow, ncol) && heights[nrow][ncol] >= heights[row][col] && !pacific[nrow][ncol]){
                        pacific[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        while(!q.empty()) q.pop();
        for(int r = 0; r < m; r++){
            q.push({r, n-1});
            atlantic[r][n-1] = true;

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop(); 
                for(int i = 0; i < 4; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if(isValid(nrow, ncol) && heights[nrow][ncol] >= heights[row][col] && !atlantic[nrow][ncol]){
                        atlantic[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        while(!q.empty()) q.pop();
        for(int c = 0; c < n; c++){
            q.push({m-1, c});
            atlantic[m-1][c] = true;

            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop(); 
                for(int i = 0; i < 4; i++){
                    int nrow = row + dr[i];
                    int ncol = col + dc[i];

                    if(isValid(nrow, ncol) && heights[nrow][ncol] >= heights[row][col] && !atlantic[nrow][ncol]){
                        atlantic[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};