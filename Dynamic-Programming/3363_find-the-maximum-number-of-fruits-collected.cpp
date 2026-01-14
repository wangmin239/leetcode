/* Official Solution 1 */
class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        auto dp = [&]() -> int {
            vector f(n - 1, vector<int>(n + 1));
            f[0][n - 1] = fruits[0][n - 1];
            for (int i = 1; i < n - 1; i++) {
                for (int j = max(n - 1 - i, i + 1); j < n; j++) {
                    f[i][j] = max({f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]}) + fruits[i][j];
                }
            }
            return f[n - 2][n - 1];
        };

        int ans = 0;
        /* start from the position (0, 0) */
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }

        /* start from the position (0, n - 1) */
        ans += dp();

        /* start from the position (n - 1, 0). */
        /* Flip the data in the lower triangle into the upper triangle. */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                fruits[j][i] = fruits[i][j];
            }
        }
        return ans + dp();
    }
};
