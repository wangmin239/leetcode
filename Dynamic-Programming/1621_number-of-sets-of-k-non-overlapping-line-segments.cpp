/* Official Solution 1 */
const int MOD = 1000000007;

class Solution {
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n), prefixSums(n + 1);
        for (int j = 0; j < n; j++) {
            dp[j] = 1;
            prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
        }
        for (int i = 1; i <= k; i++) {
            dp[0] = 0;
            for (int j = 1; j < n; j++) {
                dp[j] = (dp[j - 1] + prefixSums[j]) % MOD;
            }
            for (int j = 0; j < n; j++) {
                prefixSums[j + 1] = (prefixSums[j] + dp[j]) % MOD;
            }
        }
        return dp[n - 1];
    }
};



/* Official Solution 2 */
const int MOD = 1000000007;

class Solution {
public:
    long long quickPow(long long a, long long e) {
        long long result = 1;
        while (e > 0) {
            if (e & 1) result = result * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return result;
    }

    int numberOfSets(int n, int k) {
        int m = 2 * k;
        long long numerator = 1, denominator = 1;
        for (int i = 1; i <= m; i++) {
            numerator = numerator * (n + k - i) % MOD;
            denominator = denominator * i % MOD;
        }
        return numerator * quickPow(denominator, MOD - 2) % MOD;
    }
};


/* Official Solution 3 */
const int MOD = 1'000'000'007;
const int MX = 1999;

long long F[MX]; // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

long long qpow(long long x, int n) {
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

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
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
    int numberOfSets(int n, int k) {
        return comb(n + k - 1, k * 2);
    }
};

