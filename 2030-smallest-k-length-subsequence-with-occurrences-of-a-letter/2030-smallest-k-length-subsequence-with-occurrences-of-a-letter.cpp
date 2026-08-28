class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int x) {
        int n = s.size();

        int rem_b = count(s.begin(), s.end(), letter);
        int cnt_b = 0;
        string res = "";

        for(int i = 0; i < n; i++){
            char ch = s[i];

            // Greedily pop larger characters from the back
            while(!res.empty() && res.back() > ch){
                // Ensure remaining characters in s are enough to reach length
                if((int)res.size() - 1 + (n-i) < k) break;

                // Ensure removing 'b' won't prevent reaching the required count x
                if(res.back() == letter && cnt_b - 1 + rem_b < x) break;
                if(res.back() == letter) cnt_b--;

                res.pop_back(); 
            }

            if((int)res.size() < k){
                if(ch == letter){
                    res.push_back(ch);
                    cnt_b++;
                }
                else{
                    // If character is diff, ensure enough slots remain for needed letters
                    if(k - (int)res.size() > x - cnt_b) res.push_back(ch);
                }
            }

            if(ch == letter) rem_b--;
        }
        return res;
    }
};