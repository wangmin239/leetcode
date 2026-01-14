class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(2, vector<int>(k + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                int cur = i & 1, prev = cur ^ 1;
                f[cur][j] = (j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[prev][j - i] : 0) + f[prev][j];
                if (f[cur][j] >= mod) {
                    f[cur][j] -= mod;
                }
                else if (f[cur][j] < 0) {
                    f[cur][j] += mod;
                }
            }
        }
        return f[n & 1][k];
    }
};

class Solution
{
public:
    static const int mod = 1000000007;
    
public:
    int kInversePairs(int n, int k)
    {
        int f[2][k + 1];
        memset(f, 0, sizeof(f));
        
        f[1][0] = 1;
        for (int i = 2; i <= n; ++i)
        {
            int flip = i & 1;
            int sum = 0;
            for (int j = 0; j <= k; ++j)
            {
                sum += f[1 - flip][j];
                if (j >= i) sum -= f[1 - flip][j - i];
                if (sum < 0) sum += mod;
                if (sum >= mod) sum -= mod;
                f[flip][j] = sum;
            }
        }
        return f[n & 1][k];
    }
};