class Solution {
public:
    bool canStore(int x, int n, vector<int>& quant){
        int tot = 0;

        for(int i = 0; i < quant.size(); i++){
            tot += (quant[i] + x - 1) / x;

            if(tot > n) return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quant) {
        int m = quant.size();

        int l = 1;
        int r = *max_element(quant.begin(), quant.end());

        int ans = 0;
        while(l <= r){
            int mid = (l+r)/2;

            if(canStore(mid, n, quant)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;
    }
};