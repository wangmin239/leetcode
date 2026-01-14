class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> grid(n);
        vector<int> size(n);
        for (auto&& x : relations) {
            grid[x[0] - 1].emplace_back(x[1] - 1);
            ++size[x[1] - 1];
        }
        queue<int> q;
        for (int i = 0;i < n;++i) {
            if (size[i] == 0) q.emplace(i);
        }
        vector<int> dp(n);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            dp[x] += time[x];
            for (auto&& y : grid[x]) {
                --size[y];
                if (size[y] == 0) q.emplace(y);
                dp[y] = max(dp[x], dp[y]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int mx = 0;
        vector<vector<int>> prev(n + 1);
        for (auto &relation : relations) {
            int x = relation[0], y = relation[1];
            prev[y].emplace_back(x);
        }
        unordered_map<int, int> memo;
        function<int(int)> dp = [&](int i) -> int {
            if (!memo.count(i)) {
                int cur = 0;
                for (int p : prev[i]) {
                    cur = max(cur, dp(p));
                }
                cur += time[i - 1];
                memo[i] = cur;
            }
            return memo[i];
        };

        for (int i = 1; i <= n; i++) {
            mx = max(mx, dp(i));
        }
        return mx;
    }
};
