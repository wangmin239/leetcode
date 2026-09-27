

/* Original Solution 1 */
class Solution {
public:
    string reverseParentheses(string s) {
        int len = s.length();
        string preStr;
        stack<int> pos;
        int start;

        for (int i = 0; i < len; i++) {
            if (s[i] != '(' && s[i] != ')') {
                preStr.push_back(s[i]);
                continue;
            }

            if (s[i] == '(') {
                pos.push(preStr.length());
                continue;
            }

            start = pos.top();

            reverse(preStr.begin() + start, preStr.end());
            pos.pop();


        }
        return preStr;
    }
};



/* Official Solution 1 */
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for (auto &ch : s) {
            if (ch == '(') {
                stk.push(str);
                str = "";
            } else if (ch == ')') {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            } else {
                str.push_back(ch);
            }
        }
        return str;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j, pair[j] = i;
            }
        }

        string ret;
        int index = 0, step = 1;
        while (index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = pair[index];
                step = -step;
            } else {
                ret.push_back(s[index]);
            }
            index += step;
        }
        return ret;
    }
};
