class Solution {
public:
    string robotWithString(string s) {
        vector<int> count(26, 0);
        for(char c : s){
            count[c-'a']++;
        }

        string t = "";
        string u = "";

        int min_char = 0;
        for(char c : s){
            t.push_back(c);
            count[c-'a']--;

            while(min_char < 26 && count[min_char] == 0){
                min_char++;
            }

            while(!t.empty() && (t.back() - 'a') <= min_char){
                u.push_back(t.back());
                t.pop_back();
            }
        }

        while(!t.empty()){
            u.push_back(t.back());
            t.pop_back();
        }

        return u;
    }
};