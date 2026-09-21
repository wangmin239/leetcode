/* Official Solution 1 */
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k);
        vector<long long> dp(k);  // 初始状态，表示尚未处理任何元素，因此不存在非空子数组

        for (int i = 0; i < n; i++) {
            vector<long long> ndp(k);  // 当前层状态（滚动数组）

            ndp[nums[i] % k]++;

            for (int r = 0; r < k; r++) {
                ndp[(long long)r * nums[i] % k] += dp[r];
            }

            dp = move(ndp);  // 更新状态

            // 累加答案
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k);
        vector f(n + 1, vector<int>(k));
        for (int i = 0; i < n; i++) {
            int v = nums[i] % k; // 避免下面乘法溢出
            f[i + 1][v] = 1;
            for (int y = 0; y < k; y++) {
                f[i + 1][y * v % k] += f[i][y]; // 刷表法
            }
            for (int x = 0; x < k; x++) {
                ans[x] += f[i + 1][x];
            }
        }
        return ans;
    }
};

/* Official Solution 3 */
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k);
        vector<int> f(k); // 更快的写法见【C++ array】
        for (int v : nums) {
            v %= k; // 避免下面乘法溢出
            vector<int> nf(k);
            nf[v] = 1;
            for (int y = 0; y < k; y++) {
                nf[y * v % k] += f[y];
            }
            f = move(nf);
            for (int x = 0; x < k; x++) {
                ans[x] += f[x];
            }
        }
        return ans;
    }
};
