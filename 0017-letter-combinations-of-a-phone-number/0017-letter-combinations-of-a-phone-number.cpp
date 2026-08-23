class Solution {
public:
    void solve(int ind, string s, vector<string> &mpp, vector<string> &ans, string digits){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }

        string letters = mpp[digits[ind] - '0'];
        for(char ch : letters){
            solve(ind+1, s+ch, mpp, ans, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mpp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s = "";
        solve(0, s, mpp, ans, digits);

        return ans;
    }
};