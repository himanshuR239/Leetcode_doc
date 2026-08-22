class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();

        while(true){
            int p = s.find(part);
            if(p != string::npos){
                s.erase(p, part.size());
            }
            else break;
        }

        return s;
    }
};