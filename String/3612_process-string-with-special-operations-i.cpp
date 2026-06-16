/* Original Solution 1 */
class Solution {
public:
    string processStr(string s) {
        string ans;

        for (char ch : s) {
            switch (ch) {
                case '*':
                    if (ans.empty() == false) {
                        ans.pop_back();
                    }
                    break;
                case '#':
                    if (ans.empty() == false) {
                        ans.append(ans);
                    }
                    break;
                case '%':
                    if (ans.empty() == false) {
                        reverse(ans.begin(), ans.end());
                    }
                    break;
                default:
                    ans.push_back(ch);
            }
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c : s) {
            if (c == '*') {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            } else if (c == '#') {
                ans += ans;
            } else if (c == '%') {
                ranges::reverse(ans);
            } else {
                ans += c;
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (auto it : s) {
            if (it == '*') {
                if (result.size()) {
                    result.pop_back();
                }
            } else if (it == '#') {
                result += result;
            } else if (it == '%') {
                result = string(result.rbegin(), result.rend());
            } else {
                result += it;
            }
        }
        return result;
    }
};
