/* Official Solution 1 */
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        // known[i] 表示恰好在第 i 天得知秘密的人数
        vector<int> known(n + 1);
        known[1] = 1;
        long long ans = 0;

        for (int i = 1; i <= n; i++) {
            // 统计在第 n 天没有忘记秘密的人数
            // 这要求 i+forget-1 >= n，解得 i >= n-forget+1
            if (i >= n - forget + 1) {
                ans += known[i];
            }
            // 恰好在第 i 天得知秘密的人，会在第 [i+delay, i+forget-1] 天分享秘密
            for (int j = i + delay; j <= min(i + forget - 1, n); j++) {
                known[j] = (known[j] + known[i]) % MOD; // known[j] += known[i]
            }
        }

        return ans % MOD;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        vector<int> sum(n + 1); // known 数组的前缀和
        sum[1] = 1;

        for (int j = 2; j <= n; j++) {
            int known = (sum[max(j - delay, 0)] - sum[max(j - forget, 0)]) % MOD;
            sum[j] = (sum[j - 1] + known) % MOD;
        }

        int ans = sum[n] - sum[max(n - forget, 0)];
        return (ans % MOD + MOD) % MOD; // 保证答案非负
    }
};


/* Official Solution 3 */
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int, int>> know, share;
        know.emplace_back(1, 1);
        int know_cnt = 1, share_cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (!know.empty() && know[0].first == i - delay) {
                know_cnt = (know_cnt - know[0].second + mod) % mod;
                share_cnt = (share_cnt + know[0].second) % mod;
                share.push_back(know[0]);
                know.pop_front();
            }
            if (!share.empty() && share[0].first == i - forget) {
                share_cnt = (share_cnt - share[0].second + mod) % mod;
                share.pop_front();
            }
            if (!share.empty()) {
                know_cnt = (know_cnt + share_cnt) % mod;
                know.emplace_back(i, share_cnt);
            }
        }
        return (know_cnt + share_cnt) % mod;
    }

private:
    static constexpr int mod = 1000000007;
};
