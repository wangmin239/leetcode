/* Official Solution 1 */
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(30, 0);
        
        // 统计每个位上 1 的数量
        for (int num : nums) {
            for (int i = 0; i < 30; i++) {
                if (num & (1 << i)) {
                    cnt[i]++;
                }
            }
        }
        
        long long res = 0;
        for (int i = 0; i < k; i++) {
            long long cur = 0;
            // 从高位到低位构造当前数字
            for (int j = 29; j >= 0; j--) {
                if (cnt[j] > 0) {
                    cur |= (1LL << j);
                    cnt[j]--;
                }
            }
            res = (res + cur * cur) % MOD;
        }
        
        return (int)res;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int maxSum(vector<int> &nums, int k) {
        const int MOD = 1'000'000'007;
        int cnt[30]{};
        for (int x: nums) {
            for (int i = 0; i < 30; i++) {
                cnt[i] += (x >> i) & 1;
            }
        }
        long long ans = 0;
        while (k--) {
            int x = 0;
            for (int i = 0; i < 30; i++) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    x |= 1 << i;
                }
            }
            ans = (ans + (long long) x * x) % MOD;
        }
        return ans;
    }
};
