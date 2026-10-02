/* Original Solution 1 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int len = 2 * n;
        vector<string> ans;

        auto dfs = [&](int index, int diff, string& str, auto&& self) {

            if (index > len || diff < 0) {
                return;
            }

            if (index == len && diff == 0) {
                ans.push_back(str);
                return;
            }
            str.push_back('(');
            self(index + 1, diff + 1, str, self);

            str.pop_back();
            str.push_back(')');
            self(index + 1, diff - 1, str, self);
            str.pop_back();
        };

        string str;
        dfs(0, 0, str, dfs);
        return ans;
    }
};


/* Official Solution 1 */
class Solution {
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr)
            return cache[n];
        if (n == 0) {
            cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        } else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts)
                    for (const string& right : *rights)
                        result -> push_back("(" + left + ")" + right);
            }
            cache[n] = result;
        }
        return cache[n];
    }
    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};


/* Official Solution 2 */
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
