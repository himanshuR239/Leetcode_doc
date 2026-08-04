class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int cur = 0;
        int ind = 0;

        for(int i = 0; i < n; i++){
            int net = gas[i] - cost[i];

            total += net;
            cur += net;

            if(cur < 0){
                ind = i+1;
                cur = 0;
            }
        }

        return (total >= 0) ? ind : -1;
    }
};