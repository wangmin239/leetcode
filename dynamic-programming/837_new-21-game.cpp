
/* Original Solution 1 */
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        unordered_map<int, double> memo;
        function<double(int)> dfs = [&](int sum) {
            if (sum >= k) {
                if (sum > n) {
                    return 0.00;
                }
                return 1.00;
            }
            
            double percentage = 0.0;
            double rate = 1.00 / maxPts;
            for (int i = 1; i <= min(n, maxPts); i++) {
                int curSum = sum + i;
                if (memo.count(curSum) == 0) {
                    memo[curSum] = dfs(curSum);
                }
                percentage += memo[curSum];
            }
            
            
            percentage *= rate;
            return percentage;
        };
        
        return dfs(0);
    }
};


/* Official Solution 1 */
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        vector<double> dp(k + maxPts);
        for (int i = k; i <= n && i < k + maxPts; i++) {
            dp[i] = 1.0;
        }
        dp[k - 1] = 1.0 * min(n - k + 1, maxPts) / maxPts;
        for (int i = k - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - (dp[i + maxPts + 1] - dp[i + 1]) / maxPts;
        }
        return dp[0];
    }
};
