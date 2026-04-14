/* Official Solution 1 */
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size(), m = factory.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LONG_LONG_MAX / 2));
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                dp[i][j] = dp[i][j - 1];
                long long cost = 0;
                for (int k = 1; k <= min(i, factory[j - 1][1]); k++) {
                    cost += abs((long long)robot[i - k] - factory[j - 1][0]);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                }
            }
        }
        return dp[n][m];
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ranges::sort(factory, {}, [](auto& f) { return f[0]; });
        ranges::sort(robot);

        int m = robot.size();
        vector<long long> f(m + 1, LLONG_MAX / 2);
        f[0] = 0;

        for (auto& fac : factory) {
            int position = fac[0], limit = fac[1];

            long long dis_sum = 0;
            deque<pair<int, long long>> q;
            q.emplace_back(0, 0);

            for (int j = 1; j <= m; j++) {
                int r = robot[j - 1];
                dis_sum += abs(r - position);

                // 1. 入
                long long v = f[j] - dis_sum;
                while (!q.empty() && q.back().second >= v) {
                    q.pop_back();
                }
                q.emplace_back(j, v);

                // 2. 出
                while (q.front().first < j - limit) {
                    q.pop_front();
                }

                // 3. 队首为滑动窗口最小值
                f[j] = dis_sum + q.front().second;
            }
        }

        return f[m];
    }
};
