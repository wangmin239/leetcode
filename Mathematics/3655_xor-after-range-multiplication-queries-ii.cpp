/* Official Solution 1 */
class Solution {
    const int mod = 1e9 + 7;
    using ll = long long;
    int pow(ll x, ll y) {
        ll res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = sqrt(n);
        vector<vector<vector<int>>> groups(T);
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) {
                groups[k].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1ll * nums[i] * v % mod;
                }
            }
        }

        vector<ll> dif(n + T);
        for (int k = 1; k < T; k++) {
            if (groups[k].empty()) {
                continue;
            }
            fill(dif.begin(), dif.end(), 1);
            for (auto &q : groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                dif[l] = dif[l] * v % mod;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = dif[R] * pow(v, mod - 2) % mod;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % mod;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = 1ll * nums[i] * dif[i] % mod;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++){
            res = res ^ nums[i];
        }
        return res;
    }
};


/* Official Solution 2 */
class Solution {
    const int MOD = 1'000'000'007;

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

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int B = ceil(sqrt(queries.size()));
        vector<vector<tuple<int, int, int>>> groups(B);

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < B) {
                groups[k].emplace_back(l, r, v);
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1LL * nums[i] * v % MOD;
                }
            }
        }

        vector<int> diff(n + 1);
        for (int k = 1; k < B; k++) {
            auto& g = groups[k];
            if (g.empty()) {
                continue;
            }

            vector<vector<tuple<int, int, int>>> buckets(k);
            for (auto& t : g) {
                buckets[get<0>(t) % k].emplace_back(t);
            }

            for (int start = 0; start < k; start++) {
                auto& bucket = buckets[start];
                if (bucket.empty()) {
                    continue;
                }
                if (bucket.size() == 1) {
                    // 只有一个询问，直接暴力
                    auto& [l, r, v] = bucket[0];
                    for (int i = l; i <= r; i += k) {
                        nums[i] = 1LL * nums[i] * v % MOD;
                    }
                    continue;
                }

                int m = (n - start - 1) / k + 1;
                fill(diff.begin(), diff.begin() + m, 1);
                for (auto& [l, r, v] : bucket) {
                    diff[l / k] = 1LL * diff[l / k] * v % MOD;
                    r = (r - start) / k + 1;
                    diff[r] = diff[r] * pow(v, MOD - 2) % MOD;
                }

                long long mul_d = 1;
                for (int i = 0; i < m; i++) {
                    mul_d = mul_d * diff[i] % MOD;
                    int j = start + i * k;
                    nums[j] = nums[j] * mul_d % MOD;
                }
            }
        }

        return reduce(nums.begin(), nums.end(), 0, bit_xor());
    }
};
