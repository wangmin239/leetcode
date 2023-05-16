class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d + 1, vector<int>(n, 0x3f3f3f3f));
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            ma = max(ma, jobDifficulty[i]);
            dp[0][i] = ma;
        }
        for (int i = 1; i < d; ++i) {
            for (int j = i; j < n; ++j) {
                ma = 0;
                for (int k = j; k >= i; --k) {
                    ma = max(ma, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], ma + dp[i - 1][k - 1]);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<int> dp(n);
        for (int i = 0, j = 0; i < n; ++i) {
            j = max(j, jobDifficulty[i]);
            dp[i] = j;
        }
        for (int i = 1; i < d; ++i) {
            vector<int> ndp(n, 0x3f3f3f3f);
            for (int j = i; j < n; ++j) {
                int ma = 0;
                for (int k = j; k >= i; --k) {
                    ma = max(ma, jobDifficulty[k]);
                    ndp[j] = min(ndp[j], ma + dp[k - 1]);
                }
            }
            swap(ndp, dp);
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d, vector<int>(n));
        for (int j = 0, ma = 0; j < n; ++j) {
            ma = max(ma, jobDifficulty[j]);
            dp[0][j] = ma;
        }
        for (int i = 1; i < d; ++i) {
            stack<pair<int, int>> st;
            for (int j = i; j < n; ++j) {
                int mi = dp[i - 1][j - 1];
                while (!st.empty() && jobDifficulty[st.top().first] < jobDifficulty[j]) {
                    mi = min(mi, st.top().second);
                    st.pop();
                }
                if (st.empty()) {
                    dp[i][j] = mi + jobDifficulty[j];
                } else {
                    dp[i][j] = min(dp[i][st.top().first], mi + jobDifficulty[j]);
                }
                st.emplace(j, mi);
            }
        }
        return dp[d - 1][n - 1];
    }
};



class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<int> dp(n);
        for (int j = 0, ma = 0; j < n; ++j) {
            ma = max(ma, jobDifficulty[j]);
            dp[j] = ma;
        }
        for (int i = 1; i < d; ++i) {
            stack<pair<int, int>> st;
            vector<int> ndp(n);
            for (int j = i; j < n; ++j) {
                int mi = dp[j - 1];
                while (!st.empty() && jobDifficulty[st.top().first] < jobDifficulty[j]) {
                    mi = min(mi, st.top().second);
                    st.pop();
                }
                if (st.empty()) {
                    ndp[j] = mi + jobDifficulty[j];
                } else {
                    ndp[j] = min(ndp[st.top().first], mi + jobDifficulty[j]);
                }
                st.emplace(j, mi);
            }
            swap(dp, ndp);
        }
        return dp[n - 1];
    }
};
