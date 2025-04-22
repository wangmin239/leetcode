
/* Official Solution */
const int MOD = 1e9 + 7, MAX_N = 1e4 + 10, MAX_P = 15; // 最多有 15 个质因子
int c[MAX_N + MAX_P][MAX_P + 1];
vector<int> ps[MAX_N]; // 质因子个数列表
int sieve[MAX_N]; // 最小质因子

class Solution {
public:
    Solution() {
        if (c[0][0]){
            return;
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    sieve[j] = i;
                }
            }
        }
        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }
    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long long mul = 1;
            for (int p : ps[x]) {
                mul = mul * c[n + p - 1][p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return ans;
    }
};




#include <iostream>
#include <vector>
const int MOD = 1e9 + 7;

// 快速幂函数，用于计算 x^y % MOD
long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

// 计算组合数 C(n, k) % MOD
long long combination(int n, int k, std::vector<std::vector<long long>>& comb) {
    if (k == 0 || k == n) {
        return 1;
    }
    if (comb[n][k] != -1) {
        return comb[n][k];
    }
    comb[n][k] = (combination(n - 1, k - 1, comb) + combination(n - 1, k, comb)) % MOD;
    return comb[n][k];
}

// 主函数，计算理想数组的数目
int idealArrays(int n, int maxValue) {
    std::vector<vector<int>> divisors(maxValue + 1);
    // 预处理每个数的所有因子
    for (int i = 1; i <= maxValue; ++i) {
        for (int j = i; j <= maxValue; j += i) {
            divisors[i].push_back(j);
        }
    }
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(maxValue + 1, 0));
    // 初始化长度为 1 的数组，每个值都可以作为一个理想数组
    for (int i = 1; i <= maxValue; ++i) {
        dp[1][i] = 1;
    }
    // 动态规划计算长度为 2 到 n 的理想数组
    for (int len = 2; len <= n; ++len) {
        for (int prev = 1; prev <= maxValue; ++prev) {
            for (int next : divisors[prev]) {
                dp[len][next] = (dp[len][next] + dp[len - 1][prev]) % MOD;
            }
        }
    }
    std::vector<std::vector<long long>> comb(n + maxValue, std::vector<long long>(n + maxValue, -1));
    long long ans = 0;
    // 计算最终结果
    for (int i = 1; i <= maxValue; ++i) {
        long long ways = 0;
        for (int len = 1; len <= n; ++len) {
            ways = (ways + dp[len][i] * combination(n - 1, len - 1, comb)) % MOD;
        }
        ans = (ans + ways) % MOD;
    }
    return ans;
}

    