class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 4)), mval(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            mval[j][j] = arr[j];
            dp[j][j] = 0;
            for (int i = j - 1; i >= 0; i--) {
                mval[i][j] = max(arr[i], mval[i + 1][j]);
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        stack<int> stk;
        for (int x : arr) {
            while (!stk.empty() && stk.top() <= x) {
                int y = stk.top();
                stk.pop();
                if (stk.empty() || stk.top() > x) {
                    res += y * x;
                } else {
                    res += stk.top() * y;
                }
            }
            stk.push(x);
        }
        while (stk.size() >= 2) {
            int x = stk.top();
            stk.pop();
            res += stk.top() * x;
        }
        return res;
    }
};
