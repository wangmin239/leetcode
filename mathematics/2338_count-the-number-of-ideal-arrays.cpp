
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




/* AI Solution */
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long mod_pow(long long a, long long b, int mod) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    vector<long long> fact;
    vector<long long> inv_fact;

    void precompute_fact(int max_k) {
        fact.resize(max_k + 1);
        inv_fact.resize(max_k + 1);
        fact[0] = 1;
        for (int i = 1; i <= max_k; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[max_k] = mod_pow(fact[max_k], MOD - 2, MOD);
        for (int i = max_k - 1; i >= 0; --i) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }
    }

    vector<int> spf;

    void sieve(int max_x) {
        spf.resize(max_x + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= max_x; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_x; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<pair<int, int>> get_factors(int x) {
        vector<pair<int, int>> res;
        if (x == 1) return res;
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;
            while (x % p == 0) {
                cnt++;
                x /= p;
            }
            res.emplace_back(p, cnt);
        }
        return res;
    }

    int idealArrays(int n, int maxValue) {
        if (maxValue == 0) return 0;
        
        sieve(maxValue);
        
        int max_e_p = 0;
        for (int x = 2; x <= maxValue; ++x) {
            auto factors = get_factors(x);
            for (auto &[p, e] : factors) {
                if (e > max_e_p) {
                    max_e_p = e;
                }
            }
        }
        
        int max_k = max_e_p + n - 1;
        precompute_fact(max_k);
        
        long long ans = 0;
        for (int x = 1; x <= maxValue; ++x) {
            auto factors = get_factors(x);
            long long cnt = 1;
            for (auto &[p, e] : factors) {
                int a = e + n - 1;
                int b = n - 1;
                if (a < b) {
                    cnt = 0;
                    break;
                }
                long long comb = fact[a] * inv_fact[b] % MOD;
                comb = comb * inv_fact[a - b] % MOD;
                cnt = cnt * comb % MOD;
            }
            ans = (ans + cnt) % MOD;
        }
        
        return ans % MOD;
    }
};