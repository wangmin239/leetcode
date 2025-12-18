/* Original Solution 1 */
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long ans = LONG_MIN;
        int n = prices.size();
        long long initSum = 0;

        for (int i = 0; i < n; i++) {
            initSum += 1LL * strategy[i] * prices[i];
        }

        ans = max(ans, initSum);

        long long originSum = 0;
        long long modifySum = 0;

        /* Compute the first k elements of a vector */
        for (int i = 0; i < k; i++) {
            originSum += 1LL * strategy[i] * prices[i];

            if (i >= k / 2) {
                modifySum += prices[i];
            }
        }

        ans = max(ans, initSum + modifySum - originSum);
        for (int i = 1; i < n - k + 1; i++) {
            originSum += strategy[i + k - 1] * prices[i + k - 1];
            originSum -= strategy[i - 1] * prices[i - 1];

            modifySum += prices[i + k - 1];
            modifySum -= prices[i + (k - 1) / 2];

            ans = max(ans, initSum + modifySum - originSum);
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> sum(n + 1), sum_sell(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + prices[i] * strategy[i];
            sum_sell[i + 1] = sum_sell[i] + prices[i];
        }

        long long ans = sum[n]; // 不修改
        for (int i = k; i <= n; i++) {
            long long res = sum[i - k] + sum[n] - sum[i] + sum_sell[i] - sum_sell[i - k / 2];
            ans = max(ans, res);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long total = 0, sum = 0;
        // 计算第一个窗口的 sum
        for (int i = 0; i < k / 2; i++) {
            int p = prices[i], s = strategy[i];
            total += p * s;
            sum -= p * s;
        }
        for (int i = k / 2; i < k; i++) {
            int p = prices[i], s = strategy[i];
            total += p * s;
            sum += p * (1 - s);
        }

        long long max_sum = max(sum, 0LL);
        // 向右滑动，计算后续窗口的 sum
        for (int i = k; i < prices.size(); i++) {
            int p = prices[i], s = strategy[i];
            total += p * s;
            sum += p * (1 - s) - prices[i - k / 2] + prices[i - k] * strategy[i - k];
            max_sum = max(max_sum, sum);
        }
        return total + max_sum;
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profitSum(n + 1);
        vector<long long> priceSum(n + 1);
        for (int i = 0; i < n; i++) {
            profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
            priceSum[i + 1] = priceSum[i] + prices[i];
        }
        long long res = profitSum[n];
        for (int i = k - 1; i < n; i++) {
            long long leftProfit = profitSum[i - k + 1];
            long long rightProfit = profitSum[n] - profitSum[i + 1];
            long long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
            res = max(res, leftProfit + changeProfit + rightProfit);
        }
        return res;
    }
};
