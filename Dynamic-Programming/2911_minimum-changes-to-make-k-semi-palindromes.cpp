/* Official Solution 1 */
const int MX = 201;
vector<int> divisors[MX];

int init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            divisors[j].push_back(i);
        }
    }
    return 0;
}();

class Solution {
    int get_modify(const string &s, int begin, int end) {
        int n = end - begin;
        int res = n;
        for (int d: divisors[n]) {
            int cnt = 0;
            for (int i0 = 0; i0 < d; i0++) {
                for (int i = begin + i0, j = end - d + i0; i < j; i += d, j -= d) {
                    cnt += s[i] != s[j];
                }
            }
            res = min(res, cnt);
        }
        return res;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> modify(n - 1, vector<int>(n));
        for (int left = 0; left < n - 1; left++) {
            for (int right = left + 1; right < n; right++) {
                modify[left][right] = get_modify(s, left, right + 1);
            }
        }

        vector<int> f(modify[0]);
        for (int i = 1; i < k; i++) {
            for (int j = n - 1 - (k - 1 - i) * 2; j > i * 2; j--) { // 左右都要预留空间
                f[j] = INT_MAX;
                for (int L = i * 2; L < j; L++) {
                    f[j] = min(f[j], f[L - 1] + modify[L][j]);
                }
            }
        }
        return f[n - 1];
    }
};


/* Official Solution 2 */
class Solution {
    int segmentCost(const string &s, int l, int m, const vector<vector<int>> &factors) {
        int best = m;
        for (int d : factors[m]) {
            int groups = m / d; // 每组有 groups 个字符
            int changes = 0;
            for (int offset = 0; offset < d; offset++) {
                for (int t = 0; t < groups / 2; t++) { // 组内首尾配对
                    if (s[l + offset + t * d] != s[l + offset + (groups - 1 - t) * d]) {
                        changes++;
                    }
                }
            }
            best = min(best, changes);
        }
        return best;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> factors(n + 1);
        // 预处理每个数的真因子
        for (int d = 1; d <= n / 2; d++) {
            for (int m = d * 2; m <= n; m += d) {
                factors[m].push_back(d);
            }
        }
        vector cost(n, vector<int>(n, 0));
        for (int l = 0; l + 1 < n; l++) {
            for (int r = l + 1; r < n; r++) { // 子串长度至少为 2
                cost[l][r] = segmentCost(s, l, r - l + 1, factors);
            }
        }
        vector<int> prev(n);
        for (int start = 0; start < n; start++) { // seg = 1 的情况
            prev[start] = cost[start][n - 1];
        }
        for (int seg = 2; seg <= k; seg++) { // 段数从 2 推到 k
            vector<int> cur(n, n);
            int limit = n - 1 - 2 * (seg - 1);
            for (int start = 0; start + 2 * seg <= n; start++) { // 至少留够 2*seg 个字符
                for (int e = start + 1; e <= limit; e++) {
                    cur[start] = min(cur[start], cost[start][e] + prev[e + 1]);
                }
            }
            prev.swap(cur);
        }
        return prev[0];
    }
};
