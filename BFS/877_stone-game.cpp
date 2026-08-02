/* Original Solution 1 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        auto dfs = [&](int left, int right, auto self) {
            if (left > right) {
                return 0;
            }

            if (left == right) {
                return piles[left];
            }

            int front = piles[left] - self(left + 1, right, self);
            int back = piles[right] - self(left, right - 1, self);

            return max(front, back);
        };

        return dfs(0, n - 1, dfs) > 0;
    }
};

/* Original Solution 2 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            memo[i][i] = piles[i];
        }

        auto dfs = [&](int left, int right, auto self) {
            if (left > right) {
                return 0;
            }

            if (left == right) {
                return piles[left];
            }

            if (memo[left + 1][right] == 0) {
                memo[left + 1][right] = self(left + 1, right, self);
            }

            if (memo[left][right - 1] == 0) {
                memo[left][right - 1] = self(left, right - 1, self);
            }

            int front = piles[left] - memo[left + 1][right];
            int back = piles[right] - memo[left][right - 1];

            return max(front, back);
        };

        return dfs(0, n - 1, dfs) > 0;
    }
};



/* Original Solution 3 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }


        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
               dp[i][j] = max(piles[i] - dp[i + 1][j], dp[i][j]);
               dp[i][j] = max(piles[j] - dp[i][j - 1], dp[i][j]);
            }
        }


        return dp[0][n - 1] > 0;
    }
};





/* Original Solution 3 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }


        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
               dp[i][j] = max(piles[i] - dp[i + 1][j], dp[i][j]);
               dp[i][j] = max(piles[j] - dp[i][j - 1], dp[i][j]);
            }
        }


        return dp[0][n - 1] > 0;
    }
};




/* Official Solution 1 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int length = piles.size();
        auto dp = vector<vector<int>>(length, vector<int>(length));
        for (int i = 0; i < length; i++) {
            dp[i][i] = piles[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][length - 1] > 0;
    }
};


/* Official Solution 2 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int length = piles.size();
        auto dp = vector<int>(length);
        for (int i = 0; i < length; i++) {
            dp[i] = piles[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[length - 1] > 0;
    }
};

/* Official Solution 3 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
