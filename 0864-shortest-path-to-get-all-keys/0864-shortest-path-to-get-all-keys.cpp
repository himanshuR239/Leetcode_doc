class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int k = 0; //total keys
        int startX = -1, startY = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    startX = i;
                    startY = j;
                }
                if(islower(grid[i][j])) k++;
            }
        }

        int tarMask = (1 << k) - 1;

        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << k, false)));
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, 0, 0});
        vis[startX][startY][0] = true;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c, curMask, dist] = q.front();
            q.pop();

            if(curMask == tarMask) return dist;
 
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(grid[nr][nc] == '#') continue;

                // check lock
                if(isupper(grid[nr][nc])){
                    if(!(curMask & (1 << (grid[nr][nc] - 'A')))) continue; //checking whether we have key for this lock or not 
                }

                // pick key
                int nMask = curMask;
                if(islower(grid[nr][nc])){
                    nMask |= (1 << (grid[nr][nc] - 'a'));
                }

                if(!vis[nr][nc][nMask]){
                    vis[nr][nc][nMask] = true;
                    q.push({nr, nc, nMask, dist+1});
                }
            }
        }

        return -1;
    }
};