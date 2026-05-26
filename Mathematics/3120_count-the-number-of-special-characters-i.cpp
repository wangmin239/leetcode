/* Original Solution 1 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lowChMask = 0;
        int upChMask = 0;
        const int num = 26;
        int cnt = 0;

        for (char ch : word) {
            if (islower(ch)) {
                lowChMask |= 1 << (ch - 'a');
            } else {
                upChMask |= 1 << (ch - 'A');
            }
        }

        int mask = lowChMask & upChMask;
        for (int i = 0; i < num; i++) {
            cnt += (mask >> i) & 0x1;
        }

        return cnt;
    }
};


/* Original Solution 2 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unsigned int lowChMask = 0;
        unsigned int upChMask = 0;


        for (char ch : word) {
            if (islower(ch)) {
                lowChMask |= 1 << (ch - 'a');
            } else {
                upChMask |= 1 << (ch - 'A');
            }
        }

        return popcount(lowChMask & upChMask);
    }
};

/* Official Solution 1 */
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
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
        unordered_set<char> s(word.begin(), word.end());
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.count(c) && s.count(c - 'a' + 'A')) {
                ans++;
            }
        }
        return ans;
    }
};
