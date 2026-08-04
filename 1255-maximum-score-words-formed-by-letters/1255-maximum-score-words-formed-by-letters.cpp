class Solution {
public:
    int n;

    int solve(int ind, vector<string>& words, vector<int> &cnt, vector<int>& score){
        if(ind == n) return 0;

        // skip
        int maxi = solve(ind+1, words, cnt, score);

        // take
        bool flag = true;
        int word_score = 0;
        vector<int> temp_cnt = cnt;

        for(char ch : words[ind]){
            int i = ch - 'a';
            if(temp_cnt[i] == 0) flag = false;

            temp_cnt[i]--;
            word_score += score[i];
        }

        if(flag){
            maxi = max(maxi, word_score + solve(ind+1, words, temp_cnt, score));
        }

        return maxi;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        int l = letters.size();

        vector<int> cnt(26, 0);
        for(int i = 0; i < l; i++){
            cnt[letters[i] - 'a']++;
        }

        return solve(0, words, cnt, score);
    }
};