class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();

        vector<string> ans;
        if(n < 10) return ans;

        unordered_map<string, int> mpp;
        for(int i = 0; i <= n-10; i++){
            string temp = s.substr(i, 10);

            mpp[temp]++;

            if(mpp[temp] == 2) ans.push_back(temp);
        }

        return ans;
    }
};