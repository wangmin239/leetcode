/* Original Solution 1 */
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        constexpr int mod = 1e9 + 7;
        int len = zero + one;
        vector<int> binArr;
        auto check = [&]() {
            int len = binArr.size();

            if (len <= limit) {
                return true;
            }
            int mask = 0;
            const int required = 0x3;
            for (int i = len - limit - 1; i < len; i++) {
                mask |= (1 << binArr[i]);
                if (mask == required) {
                    return true;
                }
            }
            return false;
        };

        auto dfs = [&](int zero, int one, auto&& self) {
            if (zero == 0 && one == 0) {
                return 1;
            }

            int sum = 0;
            if (zero > 0) {
                binArr.push_back(0);
                if (check() == true) {
                    sum += self(zero - 1, one, self);
                }
                binArr.pop_back();
            }

            if (one > 0) {
                binArr.push_back(1);
                if (check() == true) {
                    sum += self(zero, one - 1, self);
                }
                binArr.pop_back();
            }

            return sum % mod;
        };

        return dfs(zero, one, dfs);
    }
};


/* Official Solution 1 */
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));
        long long mod = 1e9 + 7;
        for (int i = 0; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                if (i > limit) {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
                } else {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                }
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
                if (j > limit) {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
                } else {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                }
                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;
        vector memo(zero + 1, vector<array<int, 2>>(one + 1, {-1, -1})); // -1 表示没有计算过

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i == 0) { // 递归边界
                return k == 1 && j <= limit;
            }
            if (j == 0) { // 递归边界
                return k == 0 && i <= limit;
            }
            int& res = memo[i][j][k]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            if (k == 0) {
                // + MOD 保证答案非负
                res = ((long long) dfs(i - 1, j, 0) + dfs(i - 1, j, 1) +
                       (i > limit ? MOD - dfs(i - limit - 1, j, 1) : 0)) % MOD;
            } else {
                res = ((long long) dfs(i, j - 1, 0) + dfs(i, j - 1, 1) +
                       (j > limit ? MOD - dfs(i, j - limit - 1, 0) : 0)) % MOD;
            }
            return res;
        };

        return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
    }
};


/* Official Solution 3 */
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1'000'000'007;
        vector<vector<array<int, 2>>> f(zero + 1, vector<array<int, 2>>(one + 1));
        for (int i = 1; i <= min(limit, zero); i++) {
            f[i][0][0] = 1;
        }
        for (int j = 1; j <= min(limit, one); j++) {
            f[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                // + MOD 保证答案非负
                f[i][j][0] = ((long long) f[i - 1][j][0] + f[i - 1][j][1] + (i > limit ? MOD - f[i - limit - 1][j][1] : 0)) % MOD;
                f[i][j][1] = ((long long) f[i][j - 1][0] + f[i][j - 1][1] + (j > limit ? MOD - f[i][j - limit - 1][0] : 0)) % MOD;
            }
        }
        return (f[zero][one][0] + f[zero][one][1]) % MOD;
    }
};


/* Official Solution 4 */
const int MOD = 1'000'000'007;
const int MX = 1001;

long long F[MX]; // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1

long long pow(long long x, int n) {
    long long res = 1;
    for (; n; n /= 2) {
        if (n % 2) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = pow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

long long comb(int n, int m) {
    return F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        if (zero > one) {
            swap(zero, one); // 保证空间复杂度为 O(min(zero, one))
        }
        vector<long long> f0(zero + 3);
        for (int i = (zero - 1) / limit + 1; i <= zero; i++) {
            f0[i] = comb(zero - 1, i - 1);
            for (int j = 1; j <= (zero - i) / limit; j++) {
                f0[i] = (f0[i] + (1 - j % 2 * 2) * comb(i, j) * comb(zero - j * limit - 1, i - 1)) % MOD;
            }
        }

        long long ans = 0;
        for (int i = (one - 1) / limit + 1; i <= min(one, zero + 1); i++) {
            long long f1 = comb(one - 1, i - 1);
            for (int j = 1; j <= (one - i) / limit; j++) {
                f1 = (f1 + (1 - j % 2 * 2) * comb(i, j) * comb(one - j * limit - 1, i - 1)) % MOD;
            }
            ans = (ans + (f0[i - 1] + f0[i] * 2 + f0[i + 1]) * f1) % MOD;
        }
        return (ans + MOD) % MOD; // 保证结果非负
    }
};
