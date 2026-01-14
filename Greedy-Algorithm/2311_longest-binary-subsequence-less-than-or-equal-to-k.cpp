/* Original Solution 1 */
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int value = 0;
        int len = s.length();
        int curLen = 0;
        constexpr nonNegativeBits = sizeof(int) * 8 - 1;
        for (int i = len - 1; i >=0; i--) {
            if (s[i] == '1') {
                if (curLen >= nonNegativeBits) {
                    continue;
                }
                
                int increasement = (1 << curLen);
                if (value + increasement > k) {
                    continue;
                }
                value += increasement;
            }
            ++curLen;
        }
        
        return curLen;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
