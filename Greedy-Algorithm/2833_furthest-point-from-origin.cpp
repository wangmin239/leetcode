/* Original Solution 1 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int maxDistance = 0;
        int len = moves.length();
        auto dfs = [&](int index, int pos, auto&& self) {
            if (index == len) {
                maxDistance = max(maxDistance, abs(pos));
                return;
            }

            if (moves[index] == 'R') {
                self(index + 1, pos + 1, self);
            } else if (moves[index] == 'L') {
                self(index + 1, pos - 1, self);
            } else {
                self(index + 1, pos + 1,self);
                self(index + 1, pos - 1,self);
            }
        };

        dfs(0, 0, dfs);
        return maxDistance;
    }
};

/* Original Solution 2 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int maxDistance = 0;
        int len = moves.length();
        vector<vector<int>> dp(len + 1, vector<int>(2));

        for (int i = 0; i < len; i++) {
            if (moves[i] == 'R') {
                dp[i + 1][1] = max(dp[i][0], dp[i][1]) + 1;
                dp[i + 1][0] = min(dp[i][0], dp[i][1]) + 1;
            } else if (moves[i] == 'L') {
                dp[i + 1][1] = max(dp[i][0], dp[i][1]) - 1;
                dp[i + 1][0] = min(dp[i][0], dp[i][1]) - 1;
            } else {
                dp[i + 1][1] = max(dp[i][0], dp[i][1]) + 1;
                dp[i + 1][0] = min(dp[i][0], dp[i][1]) - 1;
            }
        }

        return max(abs(dp[len][0]), abs(dp[len][1]));
    }
};


/* Original Solution 3 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int maxDistance = 0;
        int len = moves.length();
        int curLeftPos = 0, nextLeftPos = 0;
        int curRightPos = 0, nextRightPos = 0;

        for (int i = 0; i < len; i++) {
            if (moves[i] == 'R') {
                nextRightPos = max(curLeftPos, curRightPos) + 1;
            } else if (moves[i] == 'L') {
                nextLeftPos = min(curLeftPos, curRightPos) - 1;
            } else {
                nextRightPos = max(curLeftPos, curRightPos) + 1;
                nextLeftPos = min(curLeftPos, curRightPos) - 1;
            }
            curRightPos = nextRightPos;
            curLeftPos = nextLeftPos;
        }

        return max(abs(curRightPos), abs(curLeftPos));
    }
};



/* Original Solution 4 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int rightCnt = 0;
        int leftCnt = 0;

        for (char ch : moves) {
            if (ch == 'R') {
                ++rightCnt;
            }
            if (ch == 'L') {
                ++leftCnt;
            }
        }

        auto getDistance = [&](const int changeDir) {
            int distance = 0;

            for (char ch : moves) {
                if (ch == '_') {
                    ch = changeDir;
                }

                if (ch == 'R') {
                    ++distance;
                } else  {
                    --distance;
                }
            }
            return distance;
        };

        return rightCnt >= leftCnt ? abs(getDistance('R')) : abs(getDistance('L'));
    }
};



/* Official Solution 1 */
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, B = 0;
        for (auto c : moves) {
            if (c == 'L') {
                L++;
            } else if (c == 'R') {
                R++;
            } else {
                B++;
            }
        }
        return abs(L - R) + B;
    }
};
