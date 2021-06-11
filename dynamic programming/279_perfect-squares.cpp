class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};


class Solution {
public:
    int numSquares(int n) {
        int *dp = new int [n + 1];
        int maxSqrt = static_cast<int>(sqrt(n)) + 1;
     
        fill(dp, dp + n + 1, n);
        dp[0] = 0;

        for (int val = 1; val < maxSqrt; val++) {
            int square = val * val;
            for (int num = square;  num <= n; num++) {
                dp[num] = min(dp[num], dp[num - square] + 1);
            }
        }
        
        int ret = dp[n];
        delete [] dp;
        return ret;
    }
};


class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        int maxSqrt = static_cast<int>(sqrt(n)) + 1;
        
        dp[0] = 0;

        for (int val = 1; val < maxSqrt; val++) {
            int square = val * val;
            for (int num = square;  num <= n; num++) {
                dp[num] = min(dp[num], dp[num - square] + 1);
            }
        }
        
        return dp[n];
    }
};


