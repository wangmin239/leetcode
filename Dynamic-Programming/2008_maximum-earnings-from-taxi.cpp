class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end(), [&](const vector<int> &r1, const vector<int> &r2) -> bool {
            return r1[1] < r2[1];
        });
        int m = rides.size();
        vector<long long> dp(m + 1);
        for (int i = 0; i < m; i++) {
            int j = upper_bound(rides.begin(), rides.begin() + i, rides[i][0], [](int x, const vector<int> &r) -> bool {
                return x < r[1];
            }) - rides.begin();
            dp[i + 1] = max(dp[i], dp[j] + rides[i][1] - rides[i][0] + rides[i][2]);
        }
        return dp[m];
    }
};
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        vector<long long> dp(n + 1);
        unordered_map<int, vector<vector<int>>> rideMap;
        for (const auto &ride : rides) {
            rideMap[ride[1]].push_back(ride);
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (const auto &ride : rideMap[i]) {
                dp[i] = max(dp[i], dp[ride[0]] + ride[1] - ride[0] + ride[2]);
            }
        }
        return dp[n];
    }
};
