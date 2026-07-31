class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        if(n <= 8) return n;

        vector<int> vec(26, 0);
        for(int i = 0; i < n; i++){
            vec[word[i] - 'a']++;
        }

        int ans = 0;
        sort(vec.rbegin(), vec.rend());
        for(int i = 0; i < 8; i++){
            ans += (vec[i] * 1);
        }
        for(int i = 8; i < 16; i++){
            ans += (vec[i] * 2);
        }
        for(int i = 16; i < 24; i++){
            ans += (vec[i] * 3);
        }
        for(int i = 24; i < 26; i++){
            ans += (vec[i] * 4);
        }

        return ans;
    }
};