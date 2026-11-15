/* Original Solution 1 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> preSum(n + 1, 0);
        const int mod = 1e9 + 7;
        long long ans = 0LL;

        for (int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + (arr[i] & 0x1);
        }

        for (int left = 0, right = 0; right < n; right++) {
            if ((preSum[right + 1] - preSum[left]) & 0x1) {
                ++ans;
            }
        }

        int curTotal = ans;

        for (int left = 1; left < n; left++) {
            if ((arr[left - 1] & 0x1) == 0) {
                ans += curTotal;
                ans %= mod;
                continue;
            }

            curTotal = 0;
            for (int right = left; right < n; right++) {
                if ((preSum[right + 1] - preSum[left]) & 0x1) {
                   ++curTotal;
                }
            }

            ans += curTotal;
            ans %= mod;
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MODULO = 1000000007;
        int odd = 0, even = 1;
        int subarrays = 0;
        int sum = 0;
        int length = arr.size();
        for (int i = 0; i < length; i++) {
            sum += arr[i];
            subarrays = (subarrays + (sum % 2 == 0 ? odd : even)) % MODULO;
            if (sum % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return subarrays;
    }
};

/* Official Solution 2 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, s = 0;
        for (int x : arr) {
            s += x;
            odd += s % 2;
        }
        return 1LL * odd * (arr.size() + 1 - odd) % 1'000'000'007;
    }
};

/* Official Solution 3 */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = (sum[i] + arr[i]) % 2;
        }

        // cnt[0] 统计偶数 s[i] 的个数
        // cnt[1] 统计奇数 s[i] 的个数
        int cnt[2]{};
        long long ans = 0;
        for (int s : sum) {
            ans += cnt[s ^ 1]; // 在 s 左边的奇偶性不同于 s 的个数
            cnt[s]++;
        }
        return ans % 1'000'000'007;
    }
};
