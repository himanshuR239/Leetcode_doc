class Solution {
public:
    bool canPlace(int dist, vector<int>& pos, int m){
        int cnt = 1;
        int lastPos = pos[0];

        for(int i = 0; i < pos.size(); i++){
            if(pos[i] - lastPos >= dist){
                cnt++;
                lastPos = pos[i];
            }

            if(cnt >= m) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();

        sort(pos.begin(), pos.end());

        int l = 1, r = pos[n-1] - pos[0];

        int ans = 0;
        while(l <= r) {
            int mid = (l+r) / 2;

            if(canPlace(mid, pos, m)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        return ans;
    }
};