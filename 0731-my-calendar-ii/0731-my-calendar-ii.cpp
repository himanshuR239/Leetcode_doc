class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverlap; 
    vector<pair<int, int>> pairs;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto[s, e] : doubleOverlap){
            if(max(s, startTime) < min(e, endTime)) return false;
        }

        for(auto[s, e] : pairs){
            if(max(s, startTime) < min(e, endTime)){
                doubleOverlap.push_back({max(s, startTime), min(e, endTime)});
            }
        }
        pairs.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */