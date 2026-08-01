class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        vector<int> ans;
        vector<pair<int, int>> pair(mpp.begin(), mpp.end());
        sort(pair.begin(), pair.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        for(auto it : pair){
            ans.push_back(it.first);
            if(ans.size() == k) break;
        }

        return ans;
    }
};