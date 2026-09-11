class Solution {
public:
    int n;
    unordered_set<int> st;

    void solve(int ind, int num, vector<int> &vis, vector<int>& digits){
        if(ind >= 3){
            if(num % 2 == 0) st.insert(num);
            return;
        }

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            int dig = digits[i];
            if(num == -1 && dig == 0) continue;
            vis[i] = 1;
            
            if(num == -1){
                solve(ind+1, dig, vis, digits);
            }
            else{
                solve(ind+1, num*10+dig, vis, digits);
            }

            vis[i] = 0;
        }
    }

    int totalNumbers(vector<int>& digits) {
        n = digits.size();

        vector<int> vis(n, 0);
        solve(0, -1, vis, digits);

        return st.size();
    }
};