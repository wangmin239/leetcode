/* Official Solution 1 */
class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> new_coins;
        for (int x : coins) {
            bool flag = true;
            for (int y : new_coins) {
                if (x % y == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                new_coins.push_back(x);
            }
        }
        coins = new_coins;
        
        int n = coins.size();
        int m = (1 << n);
        vector<int> bit_count(m);
        vector<ll> lcm(m, 1);
        ll l = k, r = 1ll * coins[0] * k + 1;

        for (int mask = 1; mask < m; mask++) {
            int pre_mask = mask & (mask - 1);
            int i = __builtin_ctz(mask);
            
            ll tmp = lcm[pre_mask] / gcd(lcm[pre_mask], coins[i]);
            if (tmp <= r / coins[i]) {
                lcm[mask] = tmp * coins[i];
            } else {
                lcm[mask] = r + 1;
            }
        }

        auto get = [&](ll x) -> ll {
            ll count = 0;
            for (int mask = 1; mask < m; mask++) {
                if (lcm[mask] > x) {
                    continue;
                }
                if (__builtin_popcount(mask) & 1) {
                    count += x / lcm[mask];
                } else {
                    count -= x / lcm[mask];
                }
            }
            return count;
        };

        while (l < r) {
            ll x = (l + r) >> 1;
            if (get(x) >= k) {
                r = x;
            } else {
                l = x + 1;
            }
        }
        return l;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = 0;
        int mn = INT_MAX;
        for (int x : coins) {
            bool ok = true;
            for (int j = 0; j < n; j++) {
                if (x % coins[j] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                coins[n++] = x;
                mn = min(mn, x);
            }
        }

        vector<long long> subset_lcm(1 << n);
        subset_lcm[0] = 1;
        for (int i = 0; i < n; i++) {
            int bit = 1 << i;
            for (int mask = 0; mask < bit; mask++) {
                // 刷表法 DP，在 lcm(mask) 的基础上添加 coins[i]
                subset_lcm[bit | mask] = lcm(subset_lcm[mask], coins[i]);
            }
        }

        auto check = [&](long long m) -> bool {
            long long cnt = 0;
            for (int i = 1; i < subset_lcm.size(); i++) { // 枚举所有非空子集
                cnt += popcount(1u * i) % 2 ? m / subset_lcm[i] : -m / subset_lcm[i];
            }
            return cnt >= k;
        };

        long long left = k - 1, right = 1LL * mn * k;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};
