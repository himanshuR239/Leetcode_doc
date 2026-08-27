class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int gs) {
        int n = hand.size();

        if(n % gs != 0) return false;

        sort(hand.begin(), hand.end());
        unordered_map<int, int> mpp;
        for(int num : hand) mpp[num]++;
        for(int i = 0; i < n; i++){
            int num = hand[i];
            if(mpp.find(num) == mpp.end()) continue;;
            for(int j = 0; j < gs; j++){
                if(mpp.find(num) == mpp.end()) return false;
                else{
                    mpp[num]--;
                    if(mpp[num]==0) mpp.erase(num);
                }
                num++;
            }
        }

        return true;
    }
};