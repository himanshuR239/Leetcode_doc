class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        unordered_map<int, int> mpp;
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();

            mpp[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            ans[i] = (mpp[i] - i < 0) ? 0 : mpp[i] - i;
        }

        return ans;
    }
};