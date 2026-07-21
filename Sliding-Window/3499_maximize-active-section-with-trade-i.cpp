/* Original solution 1 */
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int len = s.length();
        int maxZeroCnt = 0;
        int start = 0, end = 0;
        int left, right;
        int prefixZeroCnt = 0;
        int suffixZeroCnt;

        for (right = 0; right < len; right++) {
            if (s[right] == '0') {
                break;
            }
        }

        for (left = right; right < len; ) {
            while (right < len && s[right] == '0') {
                ++prefixZeroCnt;
                ++right;
            }

            int lastOnePos = right;
            while (right < len && s[right] == '1') {
                lastOnePos = ++right;
            }

            if (lastOnePos == len) {
                break;
            }

            suffixZeroCnt = 0;
            while (right < len && s[right] == '0') {
                ++suffixZeroCnt;
                ++right;
            }

            int curZeroCnt = suffixZeroCnt + prefixZeroCnt;
            if (curZeroCnt > maxZeroCnt) {
                start = left;
                end = right;
                maxZeroCnt = curZeroCnt;
            }
            left = lastOnePos;
            prefixZeroCnt = suffixZeroCnt;
        }


        int actCnt = 0;

        for (int i = 0; i < start; i++) {
            actCnt += s[i] - '0';
        }

        for (int i = end; i < len; i++) {
            actCnt += s[i] - '0';
        }

        return actCnt + end - start;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(), s.end(), '1');

        int i = 0;
        int bestGain = 0;
        int prev = INT_MIN, cur = 0;

        while (i < n) {
            int start = i;

            while (i < n && s[i] == s[start]) {
                ++i;
            }
            if (s[start] == '0'){
                cur = i - start;
                bestGain = max(bestGain, prev + cur);
                prev = cur;
            }

        }

        return cnt1 + bestGain;
    }
};
