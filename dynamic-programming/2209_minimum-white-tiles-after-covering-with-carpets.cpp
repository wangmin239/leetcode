/* AI Solution */
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        // dp[i][j] 表示使用 i 条地毯覆盖前 j 块砖时，未被覆盖的白色砖块的最少数目
        vector<vector<int>> dp(numCarpets + 1, vector<int>(n + 1, 0));

        // 初始化不使用地毯的情况
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] + (floor[j - 1] - '0');
        }

        // 动态规划填充 dp 数组
        for (int i = 1; i <= numCarpets; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 不使用当前地毯覆盖第 j 块砖
                dp[i][j] = dp[i][j - 1] + (floor[j - 1] - '0');
                // 如果使用当前地毯覆盖从第 j - carpetLen + 1 到第 j 块砖
                if (j >= carpetLen) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - carpetLen]);
                } else {
                    // 如果 j 小于 carpetLen，使用当前地毯可以覆盖前面所有砖
                    dp[i][j] = min(dp[i][j], dp[i - 1][0]);
                }
            }
        }

        return dp[numCarpets][n];
    }
};

/* Official Solution 1 */
class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<vector<int>> d(n + 1, vector<int>(numCarpets + 1, INF));
        for (int j = 0; j <= numCarpets; j++) {
            d[0][j] = 0;
        }
        for (int i = 1; i <= n; i++) {
            d[i][0] = d[i - 1][0] + (floor[i - 1] == '1');
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= numCarpets; j++) {
                d[i][j] = d[i - 1][j] + (floor[i - 1] == '1');
                d[i][j] = min(d[i][j], d[max(0, i - carpetLen)][j - 1]);
            }
        }

        return d[n][numCarpets];
    }
};

/* Official Solution 2 */
class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<int> d(n + 1, INF), f(n + 1, INF);
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + (floor[i - 1] == '1');
        }

        for (int j = 1; j <= numCarpets; j++) {
            f[0] = 0;
            for (int i = 1; i <= n; i++) {
                f[i] = f[i - 1] + (floor[i - 1] == '1');
                f[i] = min(f[i], d[max(0, i - carpetLen)]);
            }
            swap(d, f);
        }

        return d[n];
    }
};
