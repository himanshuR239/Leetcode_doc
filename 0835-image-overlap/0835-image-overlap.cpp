class Solution {
public:
    int n;
    int solve(int rs, int cs, vector<vector<int>>& img1, vector<vector<int>>& img2){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int nr = i + rs;
                int nc = j + cs;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    if(img1[nr][nc] == 1 && img2[i][j] == 1) cnt++;
                }
            }
        }

        return cnt;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();

        int ans = 0;

        for(int rs = -(n-1); rs < n; rs++){
            for(int cs = -(n-1); cs < n; cs++){
                ans = max(ans, solve(rs, cs, img1, img2));
            }
        }

        return ans;
    }
};