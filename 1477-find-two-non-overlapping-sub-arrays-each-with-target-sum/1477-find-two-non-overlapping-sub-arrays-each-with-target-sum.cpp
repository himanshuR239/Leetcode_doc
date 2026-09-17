class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> len(n, 1e9); // stores min length

        int l = 0;
        int sum = 0;
        int ans = 1e9;

        for(int r = 0; r < n; r++){
            sum += arr[r];

            while(sum > target){
                sum -= arr[l];
                l++;
            }

            if(sum == target){
                int curLen = r-l+1;

                if(l>0 && len[l-1] != 1e9){
                    ans = min(ans, curLen + len[l-1]);
                }
                len[r] = min(curLen, (int)(r > 0 ? len[r-1] : 1e9));
            }
            else{
                len[r] = r>0 ? len[r-1] : 1e9;
            }
        }

        return ans == 1e9 ? -1 : ans;
    }
};