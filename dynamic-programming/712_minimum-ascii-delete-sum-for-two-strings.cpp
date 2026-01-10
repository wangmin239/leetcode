/* Original Solution 1 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int rows = s1.length() + 1;
        int cols = s2.length() + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

        /* Initialize the first row and the first column */
        dp[0][0] = 0;
        /* Case 1: the string s2 is empty */
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + static_cast<int>(s1[i - 1]);
        }
        /* Case 2, the string s1 is empty */        
        for (int i = 1; i < cols; i++) {
            dp[0][i] = dp[0][i - 1] + static_cast<int>(s2[i - 1]);
        }

        /* Case 3, neither string s1 nor s2 is empty */ 
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                /* The state transition keeps the previous value as the same character */
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }

                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j]);
                dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i][j]);

            }
        }
        return dp[rows - 1][cols - 1];
    }
};

/* Official Solution 1 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }
        for (int i = 1; i <= m; i++) {
            char c1 = s1[i - 1];
            for (int j = 1; j <= n; j++) {
                char c2 = s2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};
