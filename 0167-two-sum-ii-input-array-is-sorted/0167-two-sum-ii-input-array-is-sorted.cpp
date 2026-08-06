class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[numbers[i]] = i;
        }

        for(int i = 0; i < n; i++){
            int num = numbers[i];
            int x = target - num;
            if(mpp.find(x) != mpp.end()) return {i+1, mpp[x]+1};
        }

        return {};
    }
};