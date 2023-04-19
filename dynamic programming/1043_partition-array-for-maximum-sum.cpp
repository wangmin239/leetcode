class Solution {
public:
    using ll = long long;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            int maxValue = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                d[i] = max(d[i], d[j] + maxValue * (i - j));
                if (j > 0) {
                    maxValue = max(maxValue, arr[j - 1]);
                }
            }
        }
        return d[n];
    }
};

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), dp[n];
        memset(dp, 0, sizeof dp);
        int mx = 0;
        for (int i = 0;i < k;++i) {
            mx = max(mx, arr[i]);
            dp[i] = (i + 1) * mx;
        }
        for (int i = k;i < n;++i) {
            int mx = 0;
            for (int j = 0;j < k;++j) {
                mx = max(mx, arr[i - j]);
                dp[i] = max(dp[i], mx * (j + 1) + dp[i - j - 1]);
            }
        }
        return dp[n - 1];
    }
};