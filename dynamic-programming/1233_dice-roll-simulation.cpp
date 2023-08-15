class Solution {
public:
    static constexpr int mod = 1E9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector d(n + 1, vector<int>(6, 0));
        vector<int> sum(n + 1, 0);
        sum[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                int pos = max(i - rollMax[j] - 1, 0);
                int sub = ((sum[pos] - d[pos][j]) % mod + mod) % mod;
                d[i][j] = ((sum[i - 1] - sub) % mod + mod) % mod;
                if (i <= rollMax[j]) {
                    d[i][j] = (d[i][j] + 1) % mod;
                }
                sum[i] = (sum[i] + d[i][j]) % mod;
            }
        }
        return sum[n];
    }
};


class Solution {
public:
    static constexpr int mod = 1E9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector d(n + 1, vector(6, vector<int>(16)));
        for (int j = 0; j < 6; j++) {
            d[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j]; k++) {
                    for (int p = 0; p < 6; p++) {
                        if (p != j) {
                            d[i][p][1] = (d[i][p][1] + d[i - 1][j][k]) % mod;
                        } else if (k + 1 <= rollMax[j]) {
                            d[i][p][k + 1] = (d[i][p][k + 1] + d[i - 1][j][k]) % mod;
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for (int j = 0; j < 6; j++) {
            for (int k = 1; k <= rollMax[j]; k++) {
                res = (res + d[n][j][k]) % mod;
            }
        }
        return res;
    }
};

class Solution {
public:
    static constexpr int mod = 1E9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector d(2, vector(6, vector<int>(16)));
        for (int j = 0; j < 6; j++) {
            d[1][j][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            int t = i & 1;
            for (int j = 0; j < 6; j++) {
                fill(d[t][j].begin(), d[t][j].end(), 0);
            }
            for (int j = 0; j < 6; j++) {
                for (int k = 1; k <= rollMax[j]; k++) {
                    for (int p = 0; p < 6; p++) {
                        if (p != j) {
                            d[t][p][1] = (d[t][p][1] + d[t ^ 1][j][k]) % mod;
                        } else if (k + 1 <= rollMax[j]) {
                            d[t][p][k + 1] = (d[t][p][k + 1] + d[t ^ 1][j][k]) % mod;
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for (int j = 0; j < 6; j++) {
            for (int k = 1; k <= rollMax[j]; k++) {
                res = (res + d[n & 1][j][k]) % mod;
            }
        }
        return res;
    }
};
