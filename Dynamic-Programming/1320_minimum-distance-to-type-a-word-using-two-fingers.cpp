/* Official Solution 1 */
class Solution {
public:
    int getDistance(int p, int q) {
        int x1 = p / 6, y1 = p % 6;
        int x2 = q / 6, y2 = q % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(26, INT_MAX >> 1));
        fill(dp[0].begin(), dp[0].end(), 0);
        
        for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDistance(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + d);
                if (prev == j) {
                    for (int k = 0; k < 26; ++k) {
                        int d0 = getDistance(k, cur);
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + d0);
                    }
                }
            }
        }

        int ans = *min_element(dp[n - 1].begin(), dp[n - 1].end());
        return ans;
    }
};



/* Official Solution 2 */
int dis[26][26];

auto init = [] {
    constexpr int COLUMN = 6;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dis[i][j] = abs(i / COLUMN - j / COLUMN) + abs(i % COLUMN - j % COLUMN);
        }
    }
    return 0;
}();

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        int f[26]{}, nf[26];

        for (int i = 0; i < n - 1; i++) {
            int x = word[i] - 'A', y = word[i + 1] - 'A';
            for (int another_finger = 0; another_finger < 26; another_finger++) {
                nf[another_finger] = min(f[another_finger] + dis[x][y], f[y] + dis[x][another_finger]);
            }
            swap(f, nf);
        }

        return ranges::min(f);
    }
};
