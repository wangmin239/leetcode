/* Original Solution 1 */
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int diff = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (diff > 0) {
                    result.push_back(ch);
                }
                ++diff;
            } else {
                --diff;
                if (diff > 0) {
                    result.push_back(ch);
                }
            }
        }

        return result;
    }
};

/* Official Solution 1 */
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;
        for (auto c : s) {
            if (c == ')') {
                st.pop();
            }
            if (!st.empty()) {
                res.push_back(c);
            }
            if (c == '(') {
                st.emplace(c);
            }
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;
        string res;
        for (auto c : s) {
            if (c == ')') {
                level--;
            }
            if (level) {
                res.push_back(c);
            }
            if (c == '(') {
                level++;
            }
        }
        return res;
    }
};
