class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0; 
        int j = 0;
        map<int, int> mpp;

        int ans = 0;
        while(j < n){
            mpp[fruits[j]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0){
                        mpp.erase(fruits[i]);
                    }
                    i++;
                }
            }
            if(mpp.size() <= 2){
                ans = max(ans, j-i+1);
            }
            j++;
        }
        return ans;
    }
};