class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int cntMax = 0;
        int cntMin = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cntMax++;
                cntMin++;
            }
            else if(s[i] == ')'){
                cntMax--;
                cntMin--;
            }
            else if(s[i] == '*'){
                cntMin--;
                cntMax++;
            }

            if(cntMax < 0) return false;
            if(cntMin < 0) cntMin = 0;
        }

        return cntMin == 0;
    }
};