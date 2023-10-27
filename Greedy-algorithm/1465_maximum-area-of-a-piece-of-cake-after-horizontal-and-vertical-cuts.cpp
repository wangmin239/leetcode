class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        auto calMax = [](vector<int> &arr, int boardr) -> int {
            int res = 0, pre = 0;
            for (int i : arr) {
                res = max(i - pre, res);
                pre = i;
            }
            return max(res, boardr - pre);
        };
        return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % mod;
    }
};

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxLen(INT_MIN);
        int maxWidth(INT_MAX);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        getMax(horizontalCuts, h, maxLen);
        getMax(verticalCuts, w, maxWidth);

        const int mod = 1e9 + 7;
        long mul = static_cast<long long>(maxLen) * maxWidth;
        return mul % mod;
    }
    
    void getMax(const vector<int>& cuts, const int limit, int& maxVal) {
        int n = cuts.size();
        
        maxVal = cuts.front();
        for (int i = 1; i < n; i++) {
            maxVal = max(maxVal, cuts[i] - cuts[i - 1]);
        }
        maxVal = max(maxVal, limit - cuts.back());
    }
};