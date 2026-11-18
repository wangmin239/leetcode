/* Original Solution 1 */
class Solution {
public:
    int minChanges(string s) {
        int len = s.length();
        auto dfs = [&](int pos, auto&& self) {
            int cnt = 0;

            if (pos >= len) {
                return 0;
            }

            for (int left = pos; pos < len; ++pos) {
                if (s[pos] != s[left]) {
                    break;
                }
                ++cnt;
            }

            /* consecutive and even 0 or 1 */
            if ((cnt & 0x1) == 0) {
                return self(pos, self);
            }

            return 1 + self(pos + 1, self);

        };

        return dfs(0, dfs);
    }
};


/* Original Solution 2 */
class Solution {
public:
    int minChanges(string s) {
        int len = s.length();
        int changeCnt = 0;

        for (int right = 0; right < len; ++right) {
            int cnt = 0;
            int left = right;

            while (right < len && s[right] == s[left]) {
                ++cnt;
                ++right;
            }

            if ((cnt & 0x1) == 0) {
                --right;
                continue;
            }

            ++changeCnt;
        }

        return changeCnt;
    }
};




/* Official Solution 1 */
class Solution {
public:
    int minChanges(string s) {
        int len = s.length();
        int changeCnt = 0;
        const int step = 2;

        for (int i = 0; i < len;  i += step) {
            if (s[i] != s[i + 1]) {
                ++changeCnt;
            }
        }

        return changeCnt;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i += 2) {
            ans += s[i] != s[i + 1];
        }
        return ans;
    }
};
