class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;

        int leftSmall[n], rightSmall[n];
        // leftsmall
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            leftSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // rightsmall
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            rightSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for(int i=0;i<n;i++){
            int width = rightSmall[i] - leftSmall[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }
};