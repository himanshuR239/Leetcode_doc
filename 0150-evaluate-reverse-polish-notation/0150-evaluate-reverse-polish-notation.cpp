class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        int first = -1;
        int second = -1;
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+"){
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();

                int sum = first + second;
                st.push(sum);
            }
            else if(tokens[i] == "-"){
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();

                int minus = second - first;
                st.push(minus);
            }
            else if(tokens[i] == "*"){
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();

                int mult = first * second;
                st.push(mult);
            }
            else if(tokens[i] == "/"){
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();

                int div = second / first;
                st.push(div);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};