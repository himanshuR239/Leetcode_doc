class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> seen;
        while(n != 1 && !seen.contains(n)){
            seen.insert(n);
            int temp  = 0;
            while(n > 0){
                int last = n % 10;
                temp += last * last;

                n /= 10;
            }
            n = temp;
        }

        return n == 1;
    }
};