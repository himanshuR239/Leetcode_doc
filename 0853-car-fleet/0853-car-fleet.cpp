class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.rbegin(), vec.rend());

        vector<double> time;
        for(int i = 0; i < n; i++){
            double t = (double)(target - vec[i].first) / vec[i].second;
            time.push_back(t);
        }

        int ans = 0;
        double max_time = 0.0;
        for(int i = 0; i < n; i++){
            if(time[i] > max_time){
                ans++;
                max_time = time[i];
            }
        }

        return ans;
    }
};