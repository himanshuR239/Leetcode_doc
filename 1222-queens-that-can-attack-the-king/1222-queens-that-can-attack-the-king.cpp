class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = queens.size();
        int r = king[0];
        int c = king[1];

        bool board[8][8] = {false};
        for(auto q : queens) board[q[0]][q[1]] = true;

        vector<vector<int>> ans;

        int drow[] = {0, 1, -1, 0, 1, -1, 1, -1};
        int dcol[] = {1, 0, 0, -1, 1, -1, -1, 1};


        for(int i = 0; i < 8; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            while(nr >= 0 && nr < 8 && nc >= 0 && nc < 8){
                if(board[nr][nc]){
                    ans.push_back({nr, nc});
                    break;
                }
                nr += drow[i];
                nc += dcol[i];
            }
        }
        
        return ans;
    }
};