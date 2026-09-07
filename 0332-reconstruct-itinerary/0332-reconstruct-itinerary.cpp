class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        for(auto &it : tickets){
            adj[it[0]].push_back(it[1]);
        }

        for(auto &pair : adj){
            sort(pair.second.begin(), pair.second.end(), greater<string>());
        }

        string startNode = "JFK";
        vector<string> ans;
        stack<string> st;

        st.push(startNode);
        while(!st.empty()){
            string cur = st.top();
            if(!adj[cur].empty()){
                string ngbr = adj[cur].back();
                adj[cur].pop_back();
                st.push(ngbr);
            }
            else{
                ans.push_back(cur);
                st.pop();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};