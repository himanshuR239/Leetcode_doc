class Solution {
public:
    int ans = 0;

    void solve(int ind, int cnt, vector<int> &net, vector<vector<int>>& requests){
        if(ind == requests.size()){
            for(int num : net){
                if(num != 0) return;
            }
            ans = max(ans, cnt);
            return;
        }

        solve(ind+1, cnt, net, requests); // skip requests

        //take requests
        int left = requests[ind][0];
        int enter = requests[ind][1];

        net[left]++;
        net[enter]--;
        solve(ind+1, cnt+1, net, requests);

        //backtrack
        net[left]--;
        net[enter]++;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> net(n, 0);
        solve(0, 0, net, requests); //{ind, count}

        return ans;
    }
};