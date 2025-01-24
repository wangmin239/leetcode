class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int index) -> int {
            if (2 * index + 2 >= prices.size()) {
                return prices[index];
            }
            if (!memo.count(index)) {
                int minValue = INT_MAX;
                for (int i = index + 1; i <= 2 * index + 2; i++) {
                    minValue = min(minValue, dp(i));
                }
                memo[index] = prices[index] + minValue;
            }
            return memo[index];
        };

        return dp(0);
    }
};



class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<pair<int, int>> queue;
        queue.push_front({n, 0});
        for (int i = n - 1; i >= 0; i--) {
            while (!queue.empty() && queue.back().first >= 2 * i + 3) {
                queue.pop_back();
            }
            int cur = queue.back().second + prices[i];
            while (!queue.empty() && queue.front().second >= cur) {
                queue.pop_front();
            }
            queue.push_front({i, cur});
        }
        return queue.front().second;
    }
};


#include <ranges>
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        deque dq{ pair{prices.size() + 1, 0} };
        for (auto [i, p] : views::zip(views::iota(1), prices) | views::reverse) { // 下标从1开始
            while (dq.back().first > i + i + 1) { // 弹出所有2i+1范围外的
                dq.pop_back();
            }
            p += dq.back().second;
            while (dq[0].second >= p) { // 弹出所有价格更高的
                dq.pop_front();
            }
            dq.emplace_front(i, p);
        }
        return dq[0].second;
    }
};


class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int right = min(n, i + i);
            for (int left = i; left <= right; left++) {
                dp[left] = min(dp[left], dp[i - 1] + prices[i - 1]);
            }
        }
        
        return dp[n];
    }
};
