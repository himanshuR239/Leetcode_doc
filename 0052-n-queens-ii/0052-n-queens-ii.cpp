class Solution {
public:
    void solve(int r, int c, int d1, int d2, int n, int &ans){
        if(r == n){
            ans++;
            return;
        }

        int occupied = c | d1 | d2;
        int avail = ((1 << n) - 1) & ~occupied;

        while(avail){
            int bit = avail & -avail;
            avail -= bit;
            
            solve(r+1, c | bit, (d1 | bit) >> 1, (d2 | bit) << 1, n, ans);
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        solve(0, 0, 0, 0, n, ans);

        return ans;
    }
};