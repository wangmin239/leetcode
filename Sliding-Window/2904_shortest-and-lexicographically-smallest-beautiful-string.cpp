/* Original Solution 1 */
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int minLen(n << 1);
        int cnt(0);
        int left = 0, right = 0;
        string ans;

        while (left < n && s[left] == '0') {
            ++left;
        }

        for (right = left; right < n; right++) {
            cnt += static_cast<int>(s[right] == '1');

            if (cnt == k) {
                int curLen = right - left + 1;
                if (curLen <= minLen) {
                    string curStr(s.substr(left, curLen));

                    if (curLen < minLen) {
                        ans = curStr;
                        minLen = curLen;
                    } else {
                        ans = min(ans, curStr);
                    }

                }

                ++left;
                --cnt;
                while (s[left] == '0') {
                    ++left;
                }
            }
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for (int m = k; m <= s.length(); m++) {
            string ans = "";
            for (int i = m; i <= s.length(); i++) {
                string t = s.substr(i - m, m);
                if ((ans.empty() || t < ans) && ranges::count(t, '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
        return "";
    }
};



class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if (ranges::count(s, '1') < k) {
            return "";
        }
        string ans = s;
        int cnt = 0;
        for (int left = 0, right = 0; right < s.length(); right++) {
            cnt += s[right] - '0';
            while (cnt > k || s[left] == '0') {
                cnt -= s[left] - '0';
                left++;
            }
            if (cnt == k) {
                string t = s.substr(left, right - left + 1);
                if (t.length() < ans.length() ||
                    t.length() == ans.length() && t < ans) {
                    ans = move(t);
                }
            }
        }
        return ans;
    }
};
