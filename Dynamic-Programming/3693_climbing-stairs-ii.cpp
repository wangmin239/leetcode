/* Original Solution 1 */
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const int maxStep = 3;
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= maxStep; i++) {
                if (j - i >= 0) {
                    dp[j] = min(dp[j], dp[j - i] + costs[j - 1] + i * i);
                }
            }
        }

        return dp.back();
    }
};

/* Official Solution 1*/
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            int nxt = min({a + 9, b + 4, c + 1}) + costs[i];
            a = b;
            b = c;
            c = nxt;
        }
        return c;
    }
};

