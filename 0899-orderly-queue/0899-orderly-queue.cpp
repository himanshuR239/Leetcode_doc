class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.size();
        if(n == 1) return s;
        string ans = "";
        if(k == 1){
            ans = s;
            for(int i = 0; i < n-1; i++){
                s = s.substr(1) + s[0];
                ans = min(ans, s);
            }
        }
        else{
            vector<char> temp;
            for(int i = 0; i < n; i++){
                temp.push_back(s[i]);
            }
            sort(temp.begin(), temp.end());
            for(int i = 0 ;i < n; i++){
                ans += temp[i];
            }
        }

        return ans;
    }
};