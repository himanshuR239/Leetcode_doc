class MinStack {
private:
    vector<pair<int, int>> st;

public:
    MinStack() {

    }
    
    void push(int value) {
        if(st.empty()){
            st.push_back({value, value});
        }
        else{
            int mini = min(value, st.back().second);
            st.push_back({value, mini});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */