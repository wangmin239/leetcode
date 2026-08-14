/* Original Solution 1 */
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = s.length();
        const int chNum = 26;
        int chArr[chNum] = {0};
        int maxSubLen = 0;
        int maxCnt = 2;

        for (int left = 0, right = 0; right < len; right++) {
            int id = s[right] - 'a';

            ++chArr[id];
            while (chArr[id] > maxCnt) {
                --chArr[s[left++] - 'a'];
            }

            maxSubLen = max(maxSubLen, right - left + 1);
        }

        return maxSubLen;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            array<int, 26> count{};
            for (int right = left; right < n; ++right) {
                const int index = s[right] - 'a';
                ++count[index];
                if (count[index] > 2) {
                    break;
                }
                res = max(res, right - left + 1);
            }
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maximumLengthSubstring(string s) {
        array<int, 26> count{};
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.length(); ++right) {
            int ch = s[right] - 'a';
            ++count[ch];
            while (count[ch] > 2) {
                const int ch2 = s[left] - 'a';
                --count[ch2];
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, left = 0, cnt[26]{};
        for (int i = 0; i < s.length(); i++) {
            int b = s[i] - 'a';
            cnt[b]++;
            while (cnt[b] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
