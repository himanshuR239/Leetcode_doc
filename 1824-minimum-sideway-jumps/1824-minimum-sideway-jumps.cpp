class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        int cur_lane = 2;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(obstacles[i+1] == cur_lane){
                int change_lane = -1;
                int fart_obs = -1;

                for(int l = 1; l <= 3; l++){
                    if(l == cur_lane || obstacles[i] == l) continue;

                    int next_obs_idx = i+1;
                    while(next_obs_idx <= n && obstacles[next_obs_idx] != l){
                        next_obs_idx++;
                    }

                    if(next_obs_idx > fart_obs){
                        fart_obs = next_obs_idx;
                        change_lane = l;
                    }
                }
                cur_lane = change_lane;
                ans++;
            }
        }

        return ans;
    }
};