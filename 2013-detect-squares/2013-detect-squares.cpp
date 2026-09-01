class DetectSquares {
public:
    int cnts[1001][1001] = {};
    vector<pair<int, int>> points;

    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        cnts[point[0]][point[1]]++;
        points.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;
        for(auto &[px, py] : points){
            if(px != x && py != y && abs(px-x) == abs(py-y)){
                ans += cnts[px][y]* cnts[x][py];
            }
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */