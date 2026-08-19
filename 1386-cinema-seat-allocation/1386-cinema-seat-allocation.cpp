class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int m = reservedSeats.size();

        int ans = 2*n;

        int i = 0;
        while(i < m){
            int r = reservedSeats[i][0];
            bool left = true;
            bool right = true;
            bool mid = true;

            while(i < m && r == reservedSeats[i][0]){
                int s = reservedSeats[i][1];
                if(s >= 2 && s <= 5) left = false;
                if(s >= 6 && s <= 9) right = false;
                if(s >= 4 && s <= 7) mid = false;
                i++;
            }

            if(left && right){}
            else if(left || right || mid) ans--;
            else{
                ans -= 2;
            } 
        }

        return ans;
    }
};