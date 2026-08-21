class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return stones[0];
        
        while(n > 1){
            sort(stones.begin(), stones.end());
            int x = stones[n-2];
            int y = stones[n-1];

            if(x == y){
                stones.pop_back();
                stones.pop_back();
            }
            else{
                int new_wt = y-x;
                stones.pop_back();
                stones.pop_back();

                stones.push_back(new_wt);
            }
            n = stones.size();
        }

        return n == 0 ? 0 : stones[0];
    }
};