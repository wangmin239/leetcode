/* Original Solution 1 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unsigned int lowChMask = 0;
        unsigned int upChMask = 0;
        unsigned int commonChMask = 0;

        for (char ch : word) {

            if (isupper(ch)) {
                upChMask |= 1 << (ch - 'A');
                continue;
            }

            int shift = ch - 'a';
            if ((upChMask >> shift) & 0x1) {
                commonChMask |= 1 << shift;
            }
            lowChMask |= 1 << shift;
        }

        return popcount(upChMask & lowChMask) - popcount(commonChMask);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLow(26, -1), firstUp(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 && lastLow[i] < firstUp[i]) {
                ans++;
            }
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0, upper = 0, invalid = 0;
        for (char c : word) {
            int bit = 1 << (c & 31);
            if (c & 32) { // 小写字母
                lower |= bit;
                if (upper & bit) { // c 也在 upper 中
                    invalid |= bit; // 不合法
                }
            } else { // 大写字母
                upper |= bit;
            }
        }
        // 从 lower 和 upper 的交集中去掉不合法的字母 invalid
        return popcount(1u * (lower & upper & ~invalid));
    }
};
