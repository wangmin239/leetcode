class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        auto getTrend = [](int x, int y) -> int {
            if (x == y) {
                return 0;
            }
            return x < y ? -1 : 1;
        };

        int n = temperatureA.size();
        int ans = 0, cur = 0;
        for (int i = 1; i < n; ++i) {
            int ta = getTrend(temperatureA[i - 1], temperatureA[i]);
            int tb = getTrend(temperatureB[i - 1], temperatureB[i]);
            if (ta == tb) {
                ++cur;
                ans = max(ans, cur);
            }
            else {
                cur = 0;
            }
        }
        return ans;
    }
};




class Solution {
public:
    typedef enum tagTrend {
        EQUAL = 0,
        INCR = 1,
        DECR = 2,
    } Trend;

    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int size = temperatureA.size();
        int n = 0, ans = 0;
        Trend curA, curB;
        auto getTrend = [](const int pre, const int cur) {
            if (cur > pre) {
                return INCR;
            }

            if (cur < pre) {
                return DECR;
            }

            return EQUAL;
        };

        for (int i = 1; i < size; i++) {
            curA = getTrend(temperatureA[i - 1], temperatureA[i]);
            curB = getTrend(temperatureB[i - 1], temperatureB[i]);

            if (curA == curB) {
                ++n;
            } else {
                n = 0;
            }

            ans = max(n, ans);
        }

        return ans;
    }
};