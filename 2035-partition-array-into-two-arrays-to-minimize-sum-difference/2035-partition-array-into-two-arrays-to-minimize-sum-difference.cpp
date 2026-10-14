class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N/2;

        int tot = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(n+1), right(n+1);

        for(int mask = 0; mask < (1 << n); mask++){
            int sz = 0, sumL = 0, sumR = 0;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    sz++;
                    sumL += nums[i];
                    sumR += nums[n+i];
                }
            }

            left[sz].push_back(sumL);
            right[sz].push_back(sumR);
        }

        for(int k = 0; k <= n; k++){
            sort(right[k].begin(), right[k].end());
        }

        int mini = INT_MAX;

        for(int k = 0; k <= n; k++){
            int tarK = n-k;
            for(int a : left[k]){
                int tarB = tot/2 - a;
                auto it = lower_bound(right[tarK].begin(), right[tarK].end(), tarB);

                if(it != right[tarK].end()){
                    int b = *it;
                    mini = min(mini, abs(2*(a+b) - tot));
                }

                if(it != right[tarK].begin()){
                    int b = *prev(it);
                    mini = min(mini, abs(2*(a+b) - tot));
                }

                if(mini == 0) return 0;
            }
        }

        return mini;
    }
};