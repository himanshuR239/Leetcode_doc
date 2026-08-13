class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();

        unordered_map<string, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[deadends[i]]++;
        }

        if(mpp.find("0000") != mpp.end()) return -1;
        if(target == "0000") return 0;

        vector<bool> visited(10000, false);
        queue<pair<string, int>> q;
        q.push({"0000", 0}); //{string, turns}
        visited[0] = true;

        while(!q.empty()){
            auto[cur, turns] = q.front();
            q.pop();

            if(cur == target) return turns;

            for(int i = 0; i < 4; i++){
                for(int diff : {-1, 1}){
                    string next = cur;
                    next[i] = (cur[i] - '0' + diff + 10) % 10 + '0';

                    int nextIdx = stoi(next);
                    if(mpp.find(next) == mpp.end() && !visited[nextIdx]){
                        visited[nextIdx] = true;
                        q.push({next, turns + 1});
                    }
                }
            }
        }

        return -1;
    }
};