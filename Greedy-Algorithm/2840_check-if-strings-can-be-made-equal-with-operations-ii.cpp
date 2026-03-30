/* Original Solution 1 */
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int len = s1.length();
        const int maxId = 2;
        const int alphaNum = 26;
        int s1Freq[maxId][alphaNum] = {{0}};
        int s2Freq[maxId][alphaNum] = {{0}};

        for (int i = 0; i < len; i++) {
            int id = i & 0x1;
            ++s1Freq[id][s1[i] - 'a'];
            ++s2Freq[id][s2[i] - 'a'];
        }


        auto check = [&](int id) {
            for (int i = 0; i < alphaNum; i++) {
                if (s1Freq[id][i] != s2Freq[id][i]) {
                        return false;
                }
            }
            return true;
        };

        return check(0) && check(1);

    }
};


/* Official Solution 1 */
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int cnt1[2][26]{}, cnt2[2][26]{};
        for (int i = 0; i < s1.length(); i++) {
            cnt1[i % 2][s1[i] - 'a']++;
            cnt2[i % 2][s2[i] - 'a']++;
        }
        return memcmp(cnt1, cnt2, sizeof(cnt1)) == 0;
    }
};


/* Official Solution 2 */
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int counts[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
