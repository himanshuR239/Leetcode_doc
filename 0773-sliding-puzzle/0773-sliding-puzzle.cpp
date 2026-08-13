class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
        if(board == target) return 0;

        queue<pair<vector<vector<int>>, vector<int>>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0){
                    q.push({board, {i, j, 0}});
                    break;
                }
            }
        }
        set<vector<vector<int>>> vis;
        vis.insert(board);

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!q.empty()){
            auto[cur_board, it] = q.front();
            q.pop();
            int x = it[0];
            int y = it[1];
            int swaps = it[2];

            if(cur_board == target) return swaps;

            for(int i = 0; i < 4; i++){
                int nr = x + drow[i];
                int nc = y + dcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    swap(cur_board[x][y], cur_board[nr][nc]);
                    
                    if(vis.find(cur_board) == vis.end()){
                        vis.insert(cur_board);
                        q.push({cur_board, {nr, nc, swaps+1}});
                    }

                    swap(cur_board[x][y], cur_board[nr][nc]);
                }
            }
        }

        return -1;
    }
};