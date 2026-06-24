/* Official Solution 1 */
class Solution {
private:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix mul(const Matrix& a, const Matrix& b) {
        int n = a.size();
        int m = b[0].size();
        Matrix res(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                long long r = a[i][k];
                if (r == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix powMul(Matrix base, long long exp, Matrix res) {
        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) {
            return m;
        }

        int size = 2 * m;
        Matrix u(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                u[i + m][j] = 1;
            }
        }

        Matrix dp(1, vector<long long>(size, 1));

        dp = powMul(std::move(u), n - 1, std::move(dp));

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[0][i]) % MOD;
        }

        return ans;
    }
};

/* Official Solution 2 */
constexpr int MOD = 1'000'000'007;

using matrix = vector<vector<long long>>;

// 返回矩阵 a 和矩阵 b 相乘的结果
matrix mul(matrix& a, matrix& b) {
    int n = a.size(), m = b[0].size();
    matrix c = matrix(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < a[i].size(); k++) {
            if (a[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < m; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

// a^n * f1
matrix pow_mul(matrix a, int n, matrix& f1) {
    matrix res = f1;
    while (n) {
        if (n & 1) {
            res = mul(a, res);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        matrix m(k, vector<long long>(k));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k - 1 - i; j++) {
                m[i][j] = 1;
            }
        }

        matrix f1(k, vector<long long>(1, 1));
        matrix fn = pow_mul(m, n - 1, f1);

        long long ans = 0;
        for (auto& row : fn) {
            ans += row[0];
        }
        return ans * 2 % MOD;
    }
};



/* Official Solution 2 */
class Solution {
    static constexpr int MOD = 1'000'000'007;

    int pow(long long x, int n) {
        long long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
        }
        return res;
    }

    // 给定数列的前 m 项 a，返回符合 a 的最短常系数齐次线性递推式的系数 coef（模 MOD 意义下）
    // 设 coef 长为 k，当 n >= k 时，有递推式 f(n) = coef[0] * f(n-1) + coef[1] * f(n-2) + ... + coef[k-1] * f(n-k)  （注意 coef 的顺序）
    // 初始值 f(n) = a[n]  (0 <= n < k)
    // 时间复杂度 O(m^2)，其中 m 是 a 的长度
    vector<int> berlekampMassey(const vector<int>& a) {
        vector<int> coef, pre_c, tmp;
        int pre_i = -1, pre_d = 0;

        for (int i = 0; i < a.size(); i++) {
            // d = a[i] - 递推式算出来的值
            long long d = a[i];
            for (int j = 0; j < coef.size(); j++) {
                d = (d - 1LL * coef[j] * a[i - 1 - j]) % MOD;
            }
            if (d == 0) { // 递推式正确
                continue;
            }

            // 首次算错，初始化 coef 为 i+1 个 0
            if (pre_i < 0) {
                coef.resize(i + 1);
                pre_i = i;
                pre_d = d;
                continue;
            }

            int bias = i - pre_i;
            int old_len = coef.size();
            int new_len = bias + pre_c.size();
            if (new_len > old_len) { // 递推式变长了
                tmp = coef;
                coef.resize(new_len);
            }

            // 历史错误为 pre_d = a[pre_i] - sum_j pre_c[j]*a[pre_i-1-j]
            // 现在 a[i] = sum_j coef[j]*a[i-1-j] + d
            // 联立得 a[i] = sum_j coef[j]*a[i-1-j] + d/pre_d * (a[pre_i] - sum_j pre_c[j]*a[pre_i-1-j])
            // 其中 a[pre_i] 的系数 d/pre_d 位于当前（i）的 bias-1 = i-pre_i-1 处
            long long delta = d * pow(pre_d, MOD - 2) % MOD;
            coef[bias - 1] = (coef[bias - 1] + delta) % MOD;
            for (int j = 0; j < pre_c.size(); j++) {
                coef[bias + j] = (coef[bias + j] - delta * pre_c[j]) % MOD;
            }

            if (new_len > old_len) {
                pre_c = move(tmp);
                pre_i = i;
                pre_d = d;
            }
        }

        // 计算完后，可能 coef 的末尾有 0，这些 0 不能去掉
        // 比如数列 (1,2,4,2,4,2,4,...) 的系数为 [0,1,0]，表示 f(n) = 0*f(n-1) + 1*f(n-2) + 0*f(n-3) = f(n-2)   (n >= 3)
        // 如果把末尾的 0 去掉，变成 [0,1]，就表示 f(n) = 0*f(n-1) + f(n-2) = f(n-2)   (n >= 2)
        // 看上去一样，但按照这个式子算出来的数列是错误的 (1,2,1,2,1,2,...)

        return coef;
    }

    // 给定常系数齐次线性递推式 f(n) = coef[k-1] * f(n-1) + coef[k-2] * f(n-2) + ... + coef[0] * f(n-k)
    // 以及初始值 f(i) = a[i] (0 <= i < k)
    // 返回 f(n) % MOD，其中参数 n 从 0 开始
    // 注意 coef 的顺序
    // 时间复杂度 O(k^2 log n)，其中 k 是 coef 的长度
    int kitamasa(const vector<int>& coef, const vector<int>& a, long long n) {
        if (n < a.size()) {
            return a[n] % MOD;
        }

        int k = coef.size();
        // 特判 k = 0, 1 的情况
        if (k == 0) {
            return 0;
        }
        if (k == 1) {
            return 1LL * a[0] * pow(coef[0], n) % MOD;
        }

        // 已知 f(n) 的各项系数为 A，f(m) 的各项系数为 B
        // 计算并返回 f(n+m) 的各项系数 C
        auto compose = [&](const vector<int>& A, vector<int> B) -> vector<int> {
            vector<int> C(k);
            for (int v : A) {
                for (int j = 0; j < k; j++) {
                    C[j] = (C[j] + 1LL * v * B[j]) % MOD;
                }
                // 原地计算下一组系数，比如已知 f(4) 的各项系数，现在要计算 f(5) 的各项系数
                // 倒序遍历，避免提前覆盖旧值
                int bk1 = B.back();
                for (int i = k - 1; i > 0; i--) {
                    B[i] = (B[i - 1] + 1LL * bk1 * coef[i]) % MOD;
                }
                B[0] = 1LL * bk1 * coef[0] % MOD;
            }
            return C;
        };

        // 计算 res_c，以表出 f(n) = res_c[k-1] * a[k-1] + res_c[k-2] * a[k-2] + ... + res_c[0] * a[0]
        vector<int> res_c(k), c(k);
        res_c[0] = c[1] = 1;
        for (; n > 0; n /= 2) {
            if (n % 2) {
                res_c = compose(c, move(res_c));
            }
            c = compose(c, c);
        }

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + 1LL * res_c[i] * a[i]) % MOD;
        }

        return (ans + MOD) % MOD; // 保证返回值非负
    }

    // 见上一题 3699. 锯齿形数组的总数 I
    vector<int> zigZagArraysInit(int l, int r) {
        int k = r - l + 1;
        vector<int> f(k, 1);
        vector<int> a(k * 2); // 注意 a 不包含 n=0 和 n=1 的项，所以下面 kitamasa 传入的是 n-2
        for (int i = 0; i < a.size(); i++) {
            long long pre = 0, s = 0;
            for (int j = 0; j < f.size(); j++) {
                int v = f[j];
                f[j] = pre % MOD;
                pre += v;
                s += f[j];
            }
            a[i] = s * 2 % MOD;
            ranges::reverse(f);
        }
        return a;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        vector<int> a = zigZagArraysInit(l, r);
        vector<int> coef = berlekampMassey(a);
        ranges::reverse(coef); // 注意 kitamasa 入参的顺序
        return kitamasa(coef, a, n - 2);
    }
};
