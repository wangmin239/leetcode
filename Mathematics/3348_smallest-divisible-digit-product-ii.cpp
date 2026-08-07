/* Official Solution 1 */
class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; i++) {
            while(temp % i == 0) {
                temp /= i;
            }
        }
        if (temp > 1) {
            return "-1";
        }
        int n = num.length();
        vector<long long> rem(n + 1);
        rem[0] = t;
        int pos = n - 1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }
        if (rem[n] == 1) {
            return num;
        }

        for (int i = pos; i >= 0; i--) {
            while (++num[i] <= '9') {
                long long tNow = rem[i] / gcd(rem[i], num[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--) {
                    while (tNow % k) {
                        k--;
                    }
                    tNow /= k;
                    num[j] = '0' + k;
                }
                if (tNow == 1) {
                    return num;
                }
            }
        }

        string ans;
        for (int i = 9; i > 1; i--) {
            while (t % i == 0) {
                ans += '0' + i;
                t /= i;
            }
        }
        ans += string(max(n + 1 - (int) ans.length(), 0), '1');
        ranges::reverse(ans);
        return ans;
    }
};


/* Official Solution 2 */
// 超时了，看下面的方法二吧
class Solution {
public:
    string smallestNumber(string s, long long t) {
        long long tmp = t;
        int cnt = 0;
        for (int p : {2, 3, 5, 7}) {
            while (tmp % p == 0) {
                tmp /= p;
                cnt++;
            }
        }
        if (tmp > 1) {
            return "-1";
        }

        cnt = max(cnt - (int) s.length() + 1, 1);
        s = string(cnt, '0') + s;

        int n = s.length();
        string ans(n, '0');
        vector<unordered_set<long long>> vis(n);
        auto dfs = [&](auto&& dfs, int i, long long t, bool is_limit) -> bool {
            if (i == n) {
                return t == 1;
            }
            if (!is_limit && !vis[i].insert(t).second) {
                return false;
            }

            if (is_limit && i < cnt && dfs(dfs, i + 1, t, true)) { // 填 0（跳过）
                return true;
            }

            int low = is_limit ? s[i] - '0' : 0;
            for (int d = max(low, 1); d <= 9; d++) {
                if (dfs(dfs, i + 1, t / gcd(t, d), is_limit && d == low)) {
                    ans[i] = '0' + d;
                    return true;
                }
            }
            return false;
        };
        dfs(dfs, 0, t, true);

        auto it = ranges::find_if(ans, [](char c) { return c != '0'; });
        return string(it, ans.end()); // 去掉前导零
    }
};
