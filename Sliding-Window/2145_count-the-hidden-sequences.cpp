/* Original Solution */
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minDiff = 0;
        long long maxDiff = 0;
        long long nextVal = 0;
        
        for (int diff : differences) {
            nextVal += diff;
            minDiff = min(minDiff, nextVal);
            maxDiff = max(maxDiff, nextVal);
        }
        
        if (maxDiff - minDiff > upper - lower) {
            return 0;
        }
        
        return  upper - (maxDiff - minDiff + lower)  + 1;
  
    }
};

/* Official Solution */
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        for (int d: differences) {
            cur += d;
            x = min(x, cur);
            y = max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
};

