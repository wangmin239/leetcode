/* Official Solution 1 */
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);   // 解决每道题及以后题目的最高分数
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
        }
        return dp[0];
    }
};

/* Official Solution 2 */
class Solution {
public:
   long long mostPoints(vector<vector<int>>& questions) {
       int n = questions.size();
       std::vector<long long>dp(n + 1, 0);
       for (int i = 0; i < n; i++) {
           dp[i + 1] = std::max(dp[i], dp[i + 1]);
           auto& q = questions[i];
           int next = std::min(i + 1 + q[1], n);
           dp[next] = std::max(dp[next], dp[i] + q[0]);
       }
       return dp[n];
   }
};

/* Original Solution */
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        
        dp[0] = questions.front().front();
        for (int i = 1; i < n; i++) {
            for (int end = i - 1; end >= 0; end--) {
                if (end + questions[end].back() < i) {
                    dp[i] = max(dp[end] + questions[i].front(), dp[i]);
                } else {
                    dp[i] = max(dp[i], 0LL + questions[i].front());
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};