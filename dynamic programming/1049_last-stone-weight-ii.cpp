class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size(), m = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j < stones[i]) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = dp[i][j] || dp[i][j - stones[i]];
                }
            }
        }
        for (int j = m;; --j) {
            if (dp[n][j]) {
                return sum - 2 * j;
            }
        }
    }
};


class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int m = sum / 2;
        vector<int> dp(m + 1);
        dp[0] = true;
        for (int weight : stones) {
            for (int j = m; j >= weight; --j) {
                dp[j] = dp[j] || dp[j - weight];
            }
        }
        for (int j = m;; --j) {
            if (dp[j]) {
                return sum - 2 * j;
            }
        }
    }
};
