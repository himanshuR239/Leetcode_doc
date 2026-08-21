class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        unordered_map<char, int> mpp;
        for(char c : tasks){
            mpp[c]++;
        }

        int max_freq = 0;
        int k = 0;
        for(auto it : mpp){
            max_freq = max(max_freq, it.second);
        }
        for(auto it : mpp){
            if(it.second == max_freq) k++;
        }

        int intervals = (n+1) * (max_freq - 1) + k;
        return max(m, intervals);
    }
};