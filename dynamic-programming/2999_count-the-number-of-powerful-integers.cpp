/* Official Solution 1 */
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low; // 对齐位数
        int pre_len = n - s.size();              // 前缀长度

        vector<long long> memo(n, -1);
        std::function<long long(int, bool, bool)> dfs =
            [&](int i, bool limit_low,
                bool limit_high) -> long long {
            // 递归边界
            if (i == low.size()) {
                return 1;
            }

            if (!limit_low && !limit_high && memo[i] != -1) {
                return memo[i];
            }

            int lo = limit_low ? low[i] - '0' : 0;
            int hi = limit_high ? high[i] - '0' : 9;

            long long res = 0;
            if (i < pre_len) {
                for (int digit = lo; digit <= min(hi, limit); digit++) {
                    res += dfs(i + 1, limit_low && digit == lo,
                               limit_high && digit == hi);
                }
            } else {
                int x = s[i - pre_len] - '0';
                if (lo <= x && x <= min(hi, limit)) {
                    res =
                        dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                }
            }

            if (!limit_low && !limit_high) {
                memo[i] = res;
            }
            return res;
        };
        return dfs(0, true, true);
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string start_ = to_string(start - 1), finish_ = to_string(finish);
        return calculate(finish_, s, limit) - calculate(start_, s, limit);
    }

    long long calculate(string x, string s, int limit) {
        if (x.length() < s.length()) {
            return 0;
        }
        if (x.length() == s.length()) {
            return x >= s ? 1 : 0;
        }

        string suffix = x.substr(x.length() - s.length(), s.length());
        long long count = 0;
        int preLen = x.length() - s.length();

        for (int i = 0; i < preLen; i++) {
            if (limit < (x[i] - '0')) {
                count += (long)pow(limit + 1, preLen - i);
                return count;
            }
            count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - 1 - i);
        }
        if (suffix >= s) {
            count++;
        }
        return count;
    }
};
