/* Original Solution 1 */
class Solution {
public:
    int minimumPushes(string word) {
        int minPressCnt = 0;
        int len = word.length();
        const int digitStart = 2;
        const int digitEnd = 10;
        int step = 1;

        while (len) {
           for (int digit = digitStart; digit < digitEnd; digit++) {
                minPressCnt += step;
                if (--len == 0) {
                    break;
                }
           }
           ++step;
        }
        return minPressCnt;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int minimumPushes(string word) {
        int minPressCnt = 0;
        int len = word.length();
        const int digitNum = 8;
        int step = 1;

        while (len) {
            int chNum = min(len, digitNum);

            minPressCnt += chNum * step;
            len -= chNum;
            ++step;
        }
        return minPressCnt;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i / 8 + 1;
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int m = (n - 1) / 8 + 1;
        return m * (m - 1) * 4 + (n - (m - 1) * 8) * m;
    }
};
