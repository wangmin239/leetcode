class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(51, 0));
        int mod = 1e9 + 7;

        for (int v = 0; v <= nums[0]; ++v) {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int v2 = 0; v2 <= nums[i]; ++v2) {
                for (int v1 = 0; v1 <= v2; ++v1) {
                    if (nums[i - 1] - v1 >= nums[i] - v2 && nums[i] - v2 >= 0) {
                        dp[i][v2] = (dp[i][v2] + dp[i - 1][v1]) % mod;
                    }
                }
            }
        }

        int res = 0;
        for (int v : dp[n - 1]) {
            res = (res + v) % mod;
        }
        return res;
    }
};


class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size(), m = 0, mod = 1e9 + 7;
        for (int num : nums) {
            m = max(m, num);
        }
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));
        for (int a = 0; a <= nums[0]; a++) {
            dp[0][a] = 1;
        }
        for (int i = 1; i < n; i++) {
            int d = max(0, nums[i] - nums[i - 1]);
            for (int j = d; j <= nums[i]; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j - d];
                } else {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - d]) % mod;
                }
            }
        }
        int res = 0;
        for (int num : dp[n - 1]) {
            res = (res + num) % mod;
        }
        return res;
    }
};
