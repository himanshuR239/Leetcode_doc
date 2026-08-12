class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;
        while(l <= r){
            int mid = (l+r) / 2;
            long long hr = 0;
            for(int i = 0; i < n; i++){
                if(piles[i] <= mid){
                    hr++;
                }
                else{
                    hr += (piles[i] + mid - 1) / mid;
                }
            }

            if(hr <= h){
                ans = min(ans, mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};