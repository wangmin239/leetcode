/* Official Solution 1 */
class Solution {
    static constexpr int MOD = 1e9 + 7;
    
public:
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        dp[0][0] = 1;
        
        for (int num : nums) {
            vector<vector<int>> ndp(m + 1, vector<int>(m + 1));
            for (int j = 0; j <= m; j++) {
                int divisor1 = gcd(j, num);
                for (int k = 0; k <= m; k++) {
                    int val = dp[j][k];
                    if (val == 0) {
                        continue;
                    }
                    int divisor2 = gcd(k, num);
                    ndp[j][k] = (ndp[j][k] + val) % MOD;
                    ndp[divisor1][k] = (ndp[divisor1][k] + val) % MOD;
                    ndp[j][divisor2] = (ndp[j][divisor2] + val) % MOD;
                }
            }
            dp.swap(ndp);
        }
        
        int ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + dp[j][j]) % MOD;
        }
        
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;
        int n = nums.size();
        int m = ranges::max(nums);
        vector memo(n, vector(m + 1, vector<int>(m + 1, -1))); // -1 表示没有计算过

        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0) {
                return j == k;
            }
            int& res = memo[i][j][k]; // 注意这里是引用
            if (res < 0) {
                res = ((long long) dfs(i - 1, j, k) +
                       dfs(i - 1, gcd(j, nums[i]), k) +
                       dfs(i - 1, j, gcd(k, nums[i]))) % MOD;
            }
            return res;
        };

        return (dfs(n - 1, 0, 0) - 1 + MOD) % MOD; // +MOD 防止减一后变成负数
    }
};


/* Official Solution 3 */
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        int m = ranges::max(nums);
        vector f(n + 1, vector(m + 1, vector<int>(m + 1)));
        for (int j = 1; j <= m; j++) {
            f[0][j][j] = 1;
        }
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= m; k++) {
                    f[i + 1][j][k] = ((long long) f[i][j][k] + f[i][gcd(j, x)][k] + f[i][j][gcd(k, x)]) % MOD;
                }
            }
        }
        return f[n][0][0];
    }
};


/* Official Solution 4 */
static constexpr int MOD = 1'000'000'007;
static constexpr int MX = 201;

int lcms[MX][MX], pow2[MX], pow3[MX], mu[MX];

auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = 1; j < MX; j++) {
            lcms[i][j] = lcm(i, j);
        }
    }

    pow2[0] = pow3[0] = 1;
    for (int i = 1; i < MX; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
        pow3[i] = (long long) pow3[i - 1] * 3 % MOD;
    }

    mu[1] = 1;
    for (int i = 1; i < MX; i++) {
        for (int j = i * 2; j < MX; j += i) {
            mu[j] -= mu[i];
        }
    }
    return 0;
}();

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int m = ranges::max(nums);
        // cnt[i] 表示 nums 中的 i 的倍数的个数
        vector<int> cnt(m + 1);
        for (int x : nums) {
            cnt[x]++;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] += cnt[j]; // 统计 i 的倍数的个数
            }
        }

        vector f(m + 1, vector<int>(m + 1));
        for (int g1 = 1; g1 <= m; g1++) {
            for (int g2 = 1; g2 <= m; g2++) {
                int l = lcms[g1][g2];
                int c = l <= m ? cnt[l] : 0;
                int c1 = cnt[g1], c2 = cnt[g2];
                f[g1][g2] = ((long long) pow3[c] * pow2[c1 + c2 - c * 2] - pow2[c1] - pow2[c2] + 1) % MOD;
            }
        }

        // 倍数容斥
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m / i; j++) {
                for (int k = 1; k <= m / i; k++) {
                    ans += mu[j] * mu[k] * f[j * i][k * i];
                }
            }
        }
        return (ans % MOD + MOD) % MOD; // 保证 ans 非负
    }
};
