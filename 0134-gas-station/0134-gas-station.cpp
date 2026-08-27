class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tot = 0; 
        int cur = 0; 
        int ind = 0;
        for(int i = 0; i < n; i++){
            int net = gas[i] - cost[i];

            tot += net;
            cur += net;

            if(cur < 0){
                ind = i+1;
                cur = 0;
            }
        }

        return tot >= 0 ? ind : -1;
    }
};