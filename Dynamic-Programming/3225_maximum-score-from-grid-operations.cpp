/* Official Solution 1 */
using vll = std::vector<long long>;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) {
            return 0;
        }

        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
        vector<vll> prevMax(n + 1, vll(n + 1, 0));
        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
        vector<vll> colSum(n, vll(n + 1, 0));

        for (int c = 0; c < n; c++) {
            for (int r = 1; r <= n; r++) {
                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int currH = 0; currH <= n; currH++) {
                for (int prevH = 0; prevH <= n; prevH++) {
                    if (currH <= prevH) {
                        long long extraScore = colSum[i][prevH] - colSum[i][currH];
                        dp[i][currH][prevH] = std::max(dp[i][currH][prevH], prevSuffixMax[prevH][0] + extraScore);
                    } else {
                        long long extraScore = colSum[i - 1][currH] - colSum[i - 1][prevH];
                        dp[i][currH][prevH] = std::max({dp[i][currH][prevH], prevSuffixMax[prevH][currH], prevMax[prevH][currH] + extraScore});
                    }
                }
            }

            for (int currH = 0; currH <= n; currH++) {
                prevMax[currH][0] = dp[i][currH][0];
                for (int prevH = 1; prevH <= n; prevH++) {
                    long long penalty = (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH]) : 0;
                    prevMax[currH][prevH] = std::max(prevMax[currH][prevH - 1], dp[i][currH][prevH] - penalty);
                }

                prevSuffixMax[currH][n] = dp[i][currH][n];
                for (int prevH = n - 1; prevH >= 0; prevH--) {
                    prevSuffixMax[currH][prevH] = std::max(prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
                }
            }
        }

        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
        }

        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> col_sum(n, vector<long long>(n + 1));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                col_sum[j][i + 1] = col_sum[j][i] + grid[i][j];
            }
        }

        vector<vector<array<long long, 2>>> f(n, vector<array<long long, 2>>(n + 1));
        for (int j = 0; j < n - 1; j++) {
            // 用前缀最大值优化
            long long pre_max = f[j][0][1] - col_sum[j][0];
            for (int pre = 1; pre <= n; pre++) {
                f[j + 1][pre][0] = f[j + 1][pre][1] = max(f[j][pre][0], pre_max + col_sum[j][pre]);
                pre_max = max(pre_max, f[j][pre][1] - col_sum[j][pre]);
            }

            // 用后缀最大值优化
            long long suf_max = f[j][n][0] + col_sum[j + 1][n];
            for (int pre = n - 1; pre > 0; pre--) {
                f[j + 1][pre][0] = max(f[j + 1][pre][0], suf_max - col_sum[j + 1][pre]);
                suf_max = max(suf_max, f[j][pre][0] + col_sum[j + 1][pre]);
            }

            // 单独计算 pre=0 的状态
            f[j + 1][0][0] = suf_max; // 无需考虑 f[j][0][0]，因为不能连续三列全白
            f[j + 1][0][1] = max(f[j][0][0], f[j][n][0]); // 第 j 列要么全白，要么全黑
        }

        long long ans = 0;
        for (auto& row : f[n - 1]) {
            ans = max(ans, row[0]);
        }
        return ans;
    }
};

