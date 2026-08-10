/* Official Solution 1 */
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> f(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!f[i - k * k]) {
                    f[i] = true;
                    break;
                }
            }
        }
        
        return f[n];
    }
};

/* Official Solution 2 */
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int8_t> memo(n + 1, -1); // -1 表示该状态没有计算过

        auto dfs = [&](this auto&& dfs, int i) -> bool {
            if (i == 0) {
                return false;
            }

            if (memo[i] != -1) { // 之前计算过
                return memo[i];
            }

            for (int x = 1; x * x <= i; x++) {
                if (!dfs(i - x * x)) {
                    return memo[i] = true;
                }
            }
            return memo[i] = false;
        };

        return dfs(n);
    }
};


/* Official Solution 3 */
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int8_t> f(n + 1);
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                continue;
            }
            for (int x = 1; x * x <= n - i; x++) {
                f[i + x * x] = true;
            }
        }
        return f[n];
    }
};
