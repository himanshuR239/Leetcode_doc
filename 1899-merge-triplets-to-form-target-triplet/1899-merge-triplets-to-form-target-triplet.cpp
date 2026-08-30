class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& trip, vector<int>& t) {
        bool a = false;
        bool b = false;
        bool c = false;

        for(auto it : trip){
            if(it[0] <= t[0] && it[1] <= t[1] && it[2] <= t[2]){
                if(it[0] == t[0]) a = true;
                if(it[1] == t[1]) b = true;
                if(it[2] == t[2]) c = true;
            }
        }

        return a && b && c;
    }
};