class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mpp ;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        if(mpp.find(key) == mpp.end()) return "";

        auto &vec = mpp[key];

        int l = 0;
        int r = vec.size() - 1;

        string ans = "";
        while(l <= r){
            int mid = (l+r) / 2;

            if(vec[mid].first <= timestamp){
                ans = vec[mid].second;
                l = mid+1;
            }
            else{
                r = mid-1;                
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */