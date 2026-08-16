class MyCalendarThree {
public:
    map<int, int> mpp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;

        int cnt = 0;
        int maxi = 0;
        for(auto &[key, val] : mpp){
            cnt += val;
            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */