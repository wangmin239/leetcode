class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;
        vector<long long> dp(5, 1);
        vector<long long> ndp(5);
        for (int i = 2; i <= n; ++i) {
            /* a前面可以为e,u,i */
            ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
            /* e前面可以为a,i */
            ndp[1] = (dp[0] + dp[2]) % mod;
            /* i前面可以为e,o */
            ndp[2] = (dp[1] + dp[3]) % mod;
            /* o前面可以为i */
            ndp[3] = dp[2];
            /* u前面可以为i,o */
            ndp[4] = (dp[2] + dp[3]) % mod;
            dp = ndp;
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};

using LL = long long;
using Mat = vector<vector<LL>>;

class Solution {
public:     
    Mat multiply(const Mat & matrixA, const Mat & matrixB, LL mod) {
        int m = matrixA.size();
        int n = matrixB[0].size();
        Mat res(m, vector<LL>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < matrixA[i].size(); ++k) {
                    res[i][j] = (res[i][j] + matrixA[i][k] * matrixB[k][j]) % mod;
                }
            }
        }
        return res;
    }
     
    Mat fastPow(const Mat & matrix, LL n, LL mod) {
        int m = matrix.size();
        Mat res(m, vector<LL>(m, 0));
        Mat curr = matrix;

        for (int i = 0; i < m; ++i) {
            res[i][i] = 1;
        }
        for (int i = n; i != 0; i >>= 1) {
            if (i & 1) {
                res = multiply(curr, res, mod);
            }
            curr = multiply(curr, curr, mod);
        }
        return res;
    }

    int countVowelPermutation(int n) {
        LL mod = 1e9 + 7;
        Mat factor =
        {
            {0, 1, 0, 0, 0}, 
            {1, 0, 1, 0, 0}, 
            {1, 1, 0, 1, 1}, 
            {0, 0, 1, 0, 1}, 
            {1, 0, 0, 0, 0}
        };
        Mat res = fastPow(factor, n - 1, mod);
        long long ans = 0;
        for (int i = 0; i < 5; ++i) {
            ans = (ans + accumulate(res[i].begin(), res[i].end(), 0LL)) % mod;
        }
        return  ans;
    }
};
